%% Sensorless Field-Oriented Control of PMSM Using STM32 Processor Based Boards
%
% This example implements the field-oriented control (FOC) technique to control 
% the speed of a three-phase permanent magnet synchronous motor (PMSM)
% based boards.
% For details about FOC, see
% <docid:mcb_gs#mw_2d6dd8ca-938f-44d3-8334-f5e42bf4b73b Field-Oriented Control (FOC)>.
% 
% This example uses the sensorless position estimation technique. You can select either the sliding mode observer or flux observer to estimate the position feedback for the FOC algorithm used in the example.
%
% A closed-loop FOC algorithm is used to regulate the speed and torque of a three-phase PMSM. 
% This example uses STM32 peripheral blocks from the Embedded Coder(R) Support Package for STMicroelectronics(R) STM32 Processors and MCB library blocks from Motor Control Blockset.
% Run <matlab:open_system('slLibraryBrowser') slLibraryBrowser> in MATLAB(R) Command window to open the |Simulink Library Browser|. In the opened Simulink Library Browser, 
% you can find STM32 Processor Based Boards driver library under Embedded Coder(R) Support Package for STMicroelectronics(R) STM32 Processors.
%
% The Sliding Mode Observer (SMO) block generates a sliding motion on the error between the measured and estimated position. The block
% produces an estimated value that is closely proportional to the measured position. The block uses stator voltages $({V_\alpha },{V_\beta })$ and
% currents $({I_\alpha },{I_\beta })$ as inputs and estimates the electromotive force (emf) of the motor model. It uses the emf to further estimate the rotor position
% and rotor speed. 
% The Flux Observer block uses identical inputs $({V_\alpha },{V_\beta },{I_\alpha },{I_\beta })$ to 
% estimate the stator flux, generated torque, and the rotor position.
% 
% 
% Copyright 2021-2023 The MathWorks, Inc.
%% Prerequisites
% Complete the following tutorials:
%
% * <docid:mcb_gs#mw_06882f0c-0130-4b96-9db7-35b49dfc69cf Open-Loop and Closed-Loop Control>
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_903b1be4-55e0-4690-bff6-ddca142f31f7 Open-Loop Control of 3-Phase AC Motors Using STM32 Processor Based Boards>
% 
% *NOTE*: Complete all the hardware connections and obtain the ADC offset values of $({I_\alpha },{I_\beta })$ by completing <docid:stmicroelectronicsstm32f4discovery_ug#mw_903b1be4-55e0-4690-bff6-ddca142f31f7 Open-Loop Control of 3-Phase AC Motors Using STM32 Processor Based Boards>.

%% Required Hardware
% * <https://www.st.com/en/evaluation-tools/nucleo-f401re.html Nucleo-F401re Board> or <https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-g474re.html Nucleo-G474re Board>
% * <https://www.st.com/en/ecosystems/x-nucleo-ihm07m1.html X-NUCLEO-IHM07M1: Driver expansion board>
% * <https://www.anaheimautomation.com/products/brushless/brushless-motor-item.php?sID=143&pt=i&tID=96&cID=22 BLY172S-24V-4000 - Brushless DC Motor>
% 
%% Available Models
%
% You can use the <matlab:open_system('mcb_pmsm_foc_sensorless_nucleo_f401re') mcb_pmsm_foc_sensorless_nucleo_f401re> or 
% <matlab:open_system('mcb_pmsm_foc_sensorless_nucleo_g474re') mcb_pmsm_foc_sensorless_nucleo_g474re> 
% model with the X-NUCLEO-IHM07M1 expansion board for both simulation and code generation. 
% You can also use the |open_system| command to open the Simulink(R) models. For example, use this command for a STM32 Processor based Boards:
%
%%
open_system('mcb_pmsm_foc_sensorless_nucleo_f401re.slx');
%%
%
% Click *Edit motor & inverter parameters* in the model to change the model
% parameters to fit your specific motor. Match motor voltage and power
% characteristics to the controller. In this example the current motor parameters is configured for BLY172S-24V-4000 Brushless DC motor.
%
% A conventional voltage-source inverter drives motor. The controller algorithm generates three pulse width modulation (PWM) signals using a vector PWM technique for six power switching devices. 
% The inverter measures the current of the two motor inputs (ia and ib) using two channels in injected group of analog to digital converter (ADCs) and sends the measurements to the torque control algorithm.
%
%% Peripheral Configurations
%
% *STM32CubeMX Configurations*
% 
% * *ADC configuration*
% 
% * The ADC and PWM synchornization occurs such that ADC injected group conversions start based on Timer 1 update events.  
% * The ADC channel is configured to read current feedback from the injected group conversions of *ADC 1* and the reference speed from regular group conversions.
%
% <<../open-loop-stmcubemx-configuration1.png>>
%
% * *PWM Configuration*
% 
% * PWM frequency and  PWM channels are configured. The |Timer1| is configured to generate update events to synchronize the ADC with the PWM. This synchronization is important to read current feedback at right time. 
% * The repetition counter is set to 1 to ensure update events occur once every period.
% 
% <<../open-loop-stmcubemx-configuration.png>>
%
% *Peripheral Block Configurations*
% 
% Double-click the blocks to open the block parameter configurations. Ensure the specified parameter values are the same if you want to run this example on a different hardware board. 
% 
% * *Configure Analog to Digital Converter block*
%
% The algorithm in this example uses asynchronous scheduling. The pulse width modulation (PWM) block triggers the ADC conversion. At the end of the conversion, the ADC posts an interrupt that triggers the open-loop algorithm.
%
% <<../open-loop-block-configuration2.png>>
%
% <<../open-loop-block-configuration1.png>>
% 
% * *Configure PWM Output block*
%
% Select the *Set the repetition counter after counter is enabled* parameter to update the event when the timer counter overflows.
% 
% <<../open-loop-block-configuration.png>>
%
%% Simulate Model
% 
% This example supports simulation. Follow these steps to simulate the
% model.
% 
% *1.* Open a model included with this example.
% 
% *2.* Click *Run* on the *Simulation* tab to simulate the model.
% 
% *3.* Click *Data Inspector* on the *Simulation* tab to view and analyze the simulation
% results.
% 
%% Generate Code, Deploy and Run on Target Hardware
% This section shows you to generate code and run the motor.
%
% *1.* Simulate the target model and observe the simulation results.
% 
% *2.* Complete the hardware connections. For more, see <docid:stmicroelectronicsstm32f4discovery_ug#mw_903b1be4-55e0-4690-bff6-ddca142f31f7 Open-Loop Control of 3-Phase AC Motors Using STM32 Processor Based Boards>
% 
% *3.* Compute the ADC offset values obtained from the |Open-Loop Control
% of 3-Phase AC Motors Using STM32 Processor Based Boards|. For instructions, see <docid:stmicroelectronicsstm32f4discovery_ug#mw_903b1be4-55e0-4690-bff6-ddca142f31f7 Open-Loop Control of 3-Phase AC Motors Using STM32 Processor Based Boards>.
% 
% *4.* In the *Hardware* tab, click *Monitor & Tune*. You can observe from the Diagnostic Viewer that the code is generated for the model and the host connects to the target after loading the generated executable. 
% View the Simulink Data Inspector.
%
% <<../monitor-tune.png>>
%
% *5.* To spin the motor, click the *Push Button (blue push button)* on the hardware board. 
% 
% *NOTE*:
%
% * Before starting the motor, ensure to keep the potentiometer at *0* position by rotating the potentiometer in the anti-clockwise direction.
% * Click the *Push button* to start the motor. Now gradually rotate the poteniometer in the clockwise direction to increase the speed. The close loop will start after the reference speed crosses 0.1 x |pmsm.N_base| (where, |pmsm.N_base| is the MATLAB(TM) workspace variable for base speed of the motor).
% * The motor starts running in a open-loop when the reference speed is between 0 to 0.1 x |pmsm.N_base|.
%
% *6.* Click the *Push button* again, to start running the motor in the open-loop condition.
% 
% *NOTE:* Do not run the motor (using this example) in the open-loop condition for a long time duration. The motor may draw high currents and produce excessive heat.
% 
% We designed the open-loop control to run the motor with a Reference Speed that is less than or equal to 10% of base speed.
% 
% When you run this example on the hardware at a low Reference Speed, due to a known issue, the PMSM may not follow the low Reference Speed.
%  
% *7.* Increase the motor Reference Speed beyond 10% of base speed to switch from open-loop to closed-loop control.
% 
% *NOTE:* In this example, the motor is configured to run in only one
% direction.
% 
% *8.* Observe the debug signals by performing *Monitor & tune (External
% mode)*.
% 
%% Other Things to Try
% 
% * You can try running the example using an SoC Blockset(TM) and analyse the results.
% * Try running the example using <matlab:open_system('mcb_pmsm_foc_sensorless_nucleo_g474re') mcb_pmsm_foc_sensorless_nucleo_g474re> model on |STM32G4xx Based| hardware board.  
% * You can also use Flux Observer algorithm instead of sliding mode
% observer(SMO).
% 
%% More About
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_903b1be4-55e0-4690-bff6-ddca142f31f7 Open-Loop Control of 3-Phase AC Motors Using STM32 Processor Based Boards>
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_1b68fd81-f669-4c15-84fc-c55569e35eb4 Getting Started with STMicroelectronics STM32 Processor Based Boards>
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_8b4731c6-dfe2-4357-8525-4fb8143e7f2a Using the Analog to Digital Converter Block to Support STMicroelectronics STM32 Processor Based Boards>
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_b0569aa8-ba23-46e2-8c6f-b455262aae0a Signal Monitoring and Parameter Tuning of Generated PWM Output>
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_51e75ade-7315-4160-b6f9-ab66c7a73f37 Monitoring and Tuning Using STMicroelectronics STM32 Processor Based Boards>
%