%% Estimate PMSM Parameters Using STM32 Processor
% This example determines the parameters of a permanent magnet synchronous motor (PMSM) 
% using the recommended STM32xx based board. The tool determines these parameters:
% 
% * Phase resistance, ${R_s}$ (Ohm)
% 
% * |d| and |q| axis inductances, ${L_d}$ and ${L_q}$ (Henry)
% 
% * Back-EMF constant, ${K_e}$ (Vpk_LL/krpm, where Vpk_LL is the peak voltage line-to-line measurement)
% 
% * Motor inertia, $J$ (Kg.m^2)
% 
% * Friction constant, $B$ (N.m.s)
% 
% The example accepts the minimum required inputs, runs tests on the target
% hardware, and displays the estimated parameters.
% 
% *NOTE:* This example does not support simulation. Use one of the
% supported hardware configurations to run this example.

% Copyright 2023 The MathWorks, Inc.
%% Prerequisites
% The parameter estimation tool needs the motor position as detected by either a quadrature encoder, a Hall sensor, or a sensorless flux observer. 
% In this example, the speed and motor position are measured using a sensorless flux observer. Ensure that the PMSM is in no-load condition.
% 
% Complete the following tutorials: 
% 
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_1b68fd81-f669-4c15-84fc-c55569e35eb4 Getting Started with STMicroelectronics STM32 Processor Based Boards>
% * <docid:stmicroelectronicsstm32f4discovery_ug#mw_ce4f5240-6b41-4905-ad6a-359f4d9504db Configure STM32 Processor-Based Boards using STM32CubeMX with Simulink>
% 
%% Required Hardware
% * <https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-g474re.html Nucleo-G474re Board>
% * <https://www.st.com/en/ecosystems/x-nucleo-ihm07m1.html X-NUCLEO-IHM07M1: Driver expansion board>
% * <https://www.anaheimautomation.com/products/brushless/brushless-motor-item.php?sID=143&pt=i&tID=96&cID=22 BLY172S-24V-4000 - Brushless DC Motor>
% * PMSM DC power supply as per the motor rating
%
%% Hardware Connection
% <<../hardware-connection.png>>
% 
% *Jumper Connection*
%
% Configure the following connections on X-NUCLEO-IHM07M1 board to perform
% FOC to the control BLY172S-24V-4000 motor.
%
% <<../jumper-connection.png>>
% 
%% Prepare Workspace
% 
% Open the <matlab:openExample('stm32f4discovery/EstimatePMSMParametersUsingSTM32G4BasedBoardsExample','supportingFile','mcb_stm32_param_est_host_read.slx') mcb_stm32_param_est_host_read.slx> model.
%%
open_system('mcb_stm32_param_est_host_read.slx');
%%
% 
% Enter these details in the host model to prepare the workspace:
% 
% * *Select Board* &mdash; Select the target hardware and inverter combination.
% 
% * *Communication Port* &mdash; In the block parameter
% dialog boxes of Host Serial Setup, Host Serial Receive, and Host Serial Transmit blocks, select a serial *Port* to which the hardware is connected. Select an available port from the list. For more details, see <docid:mcb_gs#mw_a00d95c0-b5ff-482d-aba8-2bfa0b4747ce Find Communication Port>.
% 
% * *Required Inputs* &mdash; Enter the motor specification and hardware setup data. You can obtain these values either from the motor datasheet or from the motor nameplate.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Input DC Voltage* &mdash; The DC supply voltage for the inverter (Volts).
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Nominal Current* &mdash; The rated current of the motor (Ampere).
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Nominal Speed* &mdash; The rated speed of the motor (RPM).
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Pole Pairs* &mdash; The number of pole pairs of the motor.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Nominal Voltage* &mdash; The rated voltage of the motor (Volts).
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Position Offset* &mdash; The position (Hall or quadrature
% encoder) sensor offset value (per-unit position) (see
% <docid:mcb_gs#mw_393e50b6-51b7-4443-9ab8-e59cd8d80cc9 Hall Offset
% Calibration for PMSM Motor>,
% <docid:mcb_gs#mw_52571b8e-639e-4a24-a8bf-b644eb78edc1 Quadrature Encoder
% Offset Calibration for PMSM Motor>, and
% <docid:mcb_gs#mw_e962ec5d-44da-4cd1-889a-c8b45491450f Per-Unit System>.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Total QEP Slits* &mdash; The number of slits available in the quadrature encoder sensor. By default, this field has a value |1000|.
% 
% *NOTE:* When updating *Required Inputs*, consider these limitations:
% 
% * The rated speed of the motor must be less than 25000 RPM.
% 
% * The tests protect the hardware from over-current faults. However, to
% ensure that these faults do not occur, keep the motor's rated current
% (entered in *Nominal Current* field) less than the maximum current
% supported by the inverter.
% 
% * If you have an SMPS-based DC power supply unit, set a safe current
% limit on the power supply for safety reasons.
% 
% *Update Advanced Parameters*
% 
% You can optionally update the advanced parameters related
% to the parameter estimation algorithm. Click the link available in the
% host model to access and update these parameters:
% 
% <<../advanced-parameter.png>>
% 
% * *Openloop Vd reference Voltage for Rs estimation* &mdash; Enter the
% reference voltage ${V_d}$, in per-unit (PU)(Volts), for open-loop configuration
% that the algorithm uses to estimate phase resistance, ${R_s}$. The
% ${V_d}$ value should be high enough to bring the rotor to zero position
% and hold it there. This value should also be high enough to generate
% readable current feedback from the motor. The ${V_d}$ value should be low
% enough to avoid rapid increase in motor temperature. This parameter uses
% the default value of |0.1| PU.
% 
% * *Rs estimation time* &mdash; Enter the time (in seconds) that the
% algorithm should take to estimate the phase resistance, ${R_s}$. This
% time should be high enough for the algorithm to obtain sufficient samples for average value
% computations (for a particular switching frequency). If the measured
% voltage and current debug signals contain noise, increase this parameter
% value so that the algorithm captures more samples for the average value
% computations. This parameter uses the default value of |2| seconds. The maximum Rs estimation time allowed is |9| seconds.
% 
% * *Frequency Sweep Range for Ld and Lq estimation* &mdash; Enter the frequency
% sweep range (in Hertz) that the algorithm uses for measuring the inductances ${L_d}$
% and ${L_q}$. The lower and upper frequency limits of this range should be high
% enough to make the rotor motionless. At the same time, these frequencies should be low
% enough for the algorithm to obtain sufficient samples (for a particular
% switching frequency). Very high frequency values result in a higher
% inductive reactance that can lead to inaccurate current
% measurements. This parameter uses the default frequency values of |400|
% and |1000| Hertz.
% 
% * *Frequency step size for Ld and Lq estimation* &mdash; Enter the step size (in Hertz)
% for the frequency sweep that the algorithm uses for measuring the
% inductances ${L_d}$ and ${L_q}$. The parameter uses the default value of
% |10| Hertz.
% 
% * *DC bias for Vd during Ld & Lq estimation* &mdash; Enter the DC bias voltage, in PU (Volts), for the ${V_d}$ and ${V_q}$ voltage perturbations that
% the algorithm uses for measuring the inductances ${L_d}$ and ${L_q}$. The
% DC bias voltage should be high enough to lock the rotor shaft. At the
% same time, it should be low enough for the algorithm to avoid
% overcurrents at the time of application of sinusoidal voltage
% perturbations. The parameter uses the default value of |0.1| PU.
% 
% * *Amplitude for Vd & Vq during Ld & Lq estimation* &mdash; Enter the
% amplitude, peak-to-peak value in PU (Volts), of the ${V_d}$ and ${V_q}$ voltage
% perturbations that the algorithm uses for measuring the inductances
% ${L_d}$ and ${L_q}$. This amplitude should be high enough to avoid
% introducing noise during ADC measurements. At the same time, it should be
% low enough for the algorithm to avoid overcurrents at the time of
% application of sinusoidal voltage perturbations. The parameter uses the
% default value of |0.05| PU.
% 
% * *Iq reference for torque control* &mdash; Enter the reference ${I_q}$
% current, in PU (Amperes), for the closed-loop torque control tests performed by the
% algorithm. This current should be low enough to avoid sudden jolts to the
% rotor shaft. At the same time, it should be high enough for the algorithm
% to overcome the inertia of the rotor shaft. The parameter uses the
% default value of |0.2| PU.
% 
% * *Under Voltage limit* &mdash; Enter the voltage limit (as percentage of the input DC voltage) for undervoltage
% protection that the algorithm provides to the motor. The parameter uses
% |80| as the default value.
% 
% * *Over Current limit* &mdash; Enter the current limit (as percentage of PMSM nominal current) for overcurrent
% protection that the algorithm provides to the motor. This value should be
% high enough for the algorithm to successfully run parameter estimation
% tests under normal conditions using the configured parameters. At the
% same time, this value should not exceed |100|. The parameter uses
% |100| as the default value.
% 
% * *End speed for Inertia estimation* &mdash; Enter the motor speed, in PU
% (RPM), used by the algorithm to calculate the motor inertia. The
% parameter uses the default value of |0.25|.
%
%% Deploy Target Models
% 
% Before starting the tests by using the parameter estimation tool, you
% need to download the binary files (|.hex|/ |.out|) generated by the target
% model into the target hardware. 
% 
% *Build and Deploy Target Model*
% 
% Use this workflow to generate and deploy the code for the target model.
% Ensure that you press *Ctrl+D* to update the workspace with the required
% input values from the host model.
% 
% Click one of these hyperlinks in the parameter estimation host model to
% open the target model (for the hardware that you are using):
%
% * For *nucleog474re* that uses the sensorless Flux Observer
% block: <matlab:open_system('mcb_param_est_sensorless_nucleo_g474re_ihm07m1') mcb_param_est_sensorless_nucleo_g474re_ihm07m1>
% 
% Click *Build, Deploy & Start* in the *Hardware* tab to deploy the target model to the hardware.
% 
% *NOTE:* Ignore the warning message |Multitask data store option in the
% Diagnostics page of the Configuration Parameter Dialog is none| displayed
% by the model advisor, by clicking the *Always Ignore* button. This is part
% of the intended workflow.
% 
% <<../mcb_data_store_warning.png>>
% 
%% Estimate Motor Parameters
% 
% Use the following steps to run the Motor Control Blockset(TM) parameter estimation tool for STM32 processor:
% 
% *1.* Ensure that you deploy the binary files (|.hex|/ |.out|) generated from
% the target model, to the target hardware. 
% 
% Then update the required details in the host model. See the section
% Prepare Workspace for information about the required inputs.
% 
% *2.* In the host model, check if the *Run-Stop* slider switch position is *Run*. Then, click *Run* in the *Simulation* tab to run the
% parameter estimation tests.
% 
% *3.* The parameter estimation process takes less than a minute to perform
% the tests. You can ignore the beep sound produced during the tests.
% 
% During an emergency, you can manually turn the *Run-Stop* slider switch to
% *Stop* position to stop the parameter estimation tests.
% 
% *4.* The host model displays the estimated motor parameters after
% successfully completing the tests.
% 
% When computing the electrical parameters (phase resistance ${R_s}$, |d|
% axis inductance ${L_d}$, and |q| axis inductance ${L_q}$), the parameter
% estimation tool keeps the motor stationary. However, the parameter
% estimation tool runs the motor to compute the mechanical parameters
% (back-EMF constant ${K_e}$, motor inertia $J$, and friction constant
% $B$).
% 
% *Note:* You can ignore the displayed mechanical parameters, if the motor
% does not run.
% 
% * When the parameter estimation tests successfully
% complete, the *Test Status* LED turns green on the host model.
% 
% * If the parameter estimation tests are interrupted,
% the *Test Status* LED turns red on the host model. The model also interrupts the tests and
% turns these LEDs red to protect the hardware from the following faults:
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Over-current fault (this fault occurs when actual current drawn from
% the power supply is more than the *Nominal Current* value mentioned in the
% *Required Inputs* section of the host model)
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Under-voltage fault (this fault occurs when input DC voltage drops
% below 80% of the *Input DC Voltage* value mentioned in the *Required
% Inputs* section of the host model)
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Serial communication fault
% 
% *5.* When the *Test Status* LED turns red, run the host model again to rerun the parameter estimation
% tests.
% 
% If the *Test Status* LED is green, check the *Ld* and *Lq* LEDs
% available in the *Parameter Validity* section of the host model. These
% LEDs indicate the following statuses:
% 
% * Green &mdash; Indicates that the computed *Ld* and *Lq* values are
% valid.
% 
% * Amber &mdash; Indicates that the computed *Ld* and *Lq* values are
% invalid. Run the host model again to rerun the parameter estimation
% tests.
% 
% *6.* Use the *Signal from Target* field on the host model to select a
% debug signal that you want to monitor. After selecting a signal, open the
% *SelectedSignal* time scope (available in the *Signal Conditioning, Scaling and Advanced
% Algorithm Parameters* subsystem) to view the selected debug signal.
% 
% The parameter estimation tool uses the following algorithm to estimate parameters:
% 
% * Phase resistance, ${R_s}$ &mdash; The tool uses Ohm's law to estimate this value.
% 
% * |d| axis inductance, ${L_d}$ &mdash; The tool uses frequency injection method to estimate these values.
% 
% * |q| axis inductance, ${L_q}$ &mdash; The tool uses frequency injection method to estimate these values.
% 
% * Back-EMF constant, ${K_e}$ &mdash; The tool measures the currents and voltages and uses the electric motor equation to estimate this value.
% 
% * Motor inertia, $J$ &mdash; The tool estimates this value by using retardation test.
% 
% * Friction constant, $B$ &mdash; The tool estimates this value by using the torque equation for a motor running at a constant speed.
% 
%% Save Estimated Parameters
% 
% You can export the estimated motor parameters and further use them for the simulation and control system design.
% 
% To export, click *Save Parameters* to save the estimated parameters into a MAT (|.mat|) file.
% 
% To view the saved parameters, load the MAT (|.mat|) file in the MATLAB(R)
% workspace. MATLAB(R) saves the parameters in a structure named |motorParam| in
% the workspace.
% 
% <<../mcb_matfile_savemodel.png>>
% 
% Click *Open Model* to create a new Simulink(R) model with a PMSM motor block.
% The motor block uses the |motorParam| structure variables from the MATLAB
% workspace.