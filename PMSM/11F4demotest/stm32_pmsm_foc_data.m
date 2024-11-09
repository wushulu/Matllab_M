%% Model initialization callback for the model the following models:
%	
% Model         :   Closed Loop Control of 3-phase motors
% Description   :   Set Parameters for Closed Loop Control of 3-phase motors
% File name     :   stm32_pmsm_foc_data.m
% Model name    :   mcb_pmsm_foc_sensorless_nucleo_f401re.slx


% Copyright 2021 The MathWorks, Inc.

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;    %Hz          // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s  // PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;        %sec        // Sample time step for controller
Ts_simulink     = T_pwm/2;      %sec        // Simulation time step for model simulation
Ts_motor        = T_pwm/2;      %Sec        // Simulation sample time
Ts_inverter     = T_pwm/2;      %sec        // Simulation time step for average value inverter
Ts_speed        = 10*Ts;        %Sec        // Sample time for speed controller

%% Set data type for controller & code-gen
dataType = 'single';            % Floating point code-generation

%% System Parameters // Hardware parameters

% Set Target Parameters
target.CPU_frequency        = 84e6;					%Hz     // Clock frequency
target.PWM_frequency        = PWM_frequency;   		%Hz     // PWM frequency
target.PWM_Counter_Period   = round(target.CPU_frequency/target.PWM_frequency/2); % //PWM timer counts for up-down counter
target.ADC_Vref             = 3.3;					%V		// ADC voltage reference for LAUNCHXL-F28379D
target.ADC_MaxCount         = 4095;					%		// Max count for 12 bit ADC

pmsm = mcb_SetPMSMMotorParameters('BLY172S');
pmsm.PositionOffset = 0.1917; % Sensorless not required

% Set inverter details
inverter.model         = 'X-NUCLEO-IHM07M1'; 	% 		// Manufacturer Model Number
inverter.sn            = 'INV_XXXX';         	% 		// Manufacturer Serial Number
inverter.V_dc          = 24;       				%V      // DC Link Voltage of the Inverter (Required for motor)
inverter.I_trip        = 3.55;       			%Amps   // Max current for trip
inverter.Rds_on        = 2e-3;     				%Ohms   // Rds ON for X-NUCLEO-IHM07M1 (From motor driver chip)
inverter.Rshunt        = 0.33;    				%Ohms   // Rshunt for X-NUCLEO-IHM07M1
inverter.CtSensAOffset = 1665;        			%Counts // ADC Offset for phase-A
inverter.CtSensBOffset = 1943;        			%Counts // ADC Offset for phase-B
inverter.ADCGain       = 1;                     %       // ADC Gain factor scaled by SPI (On board amplification is not possible)
inverter.EnableLogic   = 1;    					% 		// Active high for X-NUCLEO-IHM07M1 enable pin (EN_GATE)
inverter.invertingAmp  = -1;   					% 		// Non inverting current measurement amplifier
                                                %       // With respect to modelling conventions, current is positive
                                                %       // when current is measured flowing out of motor terminal and
                                                %       // amplified with inverting amplifier. In STM board, current
                                                %       // amplified with non-inverting amplifier. Hence considerd -1.
inverter.ISenseVref    = 3.3;					%V 		// Voltage ref of inverter current sense circuit
inverter.ISenseVoltPerAmp = 0.505; 				%V/Amps // Current sense voltage output per 1 A current (Rshunt * iSense op-amp gain)
inverter.ISenseMax     = inverter.ISenseVref/(2*inverter.ISenseVoltPerAmp); %Amps // Maximum Peak-Neutral current that can be measured by inverter current sense
inverter.R_board       = inverter.Rds_on + inverter.Rshunt/3;  %Ohms
inverter.ADCOffsetCalibEnable = false;

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc
% mcb_getCharacteristics(pmsm,inverter);

%% PU System details // Set base values for pu conversion
PU_System = mcb_SetPUSystem(pmsm,inverter);

%% Set Acceleration
acceleration = 20000/PU_System.N_base;                  %  P.U/Sec // Maximum allowable acceleraton

%% Open loop reference values
T_Ref_openLoop          = 1;                    % Sec // Time for open-loop start-up
Speed_openLoop_PU       = 0.1;                  % PU  // Per-Unit speed referene for open-loop start-up
Vd_Ref_openLoop_PU      = Speed_openLoop_PU*2;  % Use 1.2x for Dyno setup and 2x for others

%% Controller design // Get ballpark values!
PI_params = mcb.internal.SetControllerParameters(pmsm,inverter,PU_System,T_pwm,2*Ts,Ts_speed);

% Set SMO parameters
%smo = mcb_ComputeSMOParameters(pmsm,Ts,PU_System);
% Values are derived from SMO block after pressing compute default
% parameters button.
smo.BackEmfObsGain = 0.9;
smo.CurrentObsGain = 0.14127;
smo.CutoffFreq = 600;

%Updating delays for simulation
PI_params.delay_Currents    = int32(Ts/Ts_simulink);
PI_params.delay_Position    = int32(Ts/Ts_simulink);
PI_params.delay_Speed       = int32(Ts_speed/Ts_simulink);
PI_params.delay_Speed1      = (PI_params.delay_IIR + 0.5*Ts)/Ts_speed;

% mcb_getControlAnalysis(pmsm,inverter,PU_System,PI_params,Ts,Ts_speed);
motor = pmsm;
motor.polePairs = pmsm.p;
motor.base_speed = 4000;
motor.base_freq = motor.base_speed*motor.polePairs/60;

% Convert all parameters of datatype double to single
%% Displaying model variables
disp(pmsm);
disp(inverter);
disp(target);
disp(PU_System);
