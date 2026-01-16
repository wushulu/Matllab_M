function mcb_stm32_param_est_InitFunc(hostModelName)
% MCB_STM32_PARAM_EST_INITFUNC Initialization function for parameter estimation

% Copyright 2022 The MathWorks, Inc.

% Motor driver parameters
simTime = 30;
motorParam.v_dc = str2double(get_param([hostModelName '/Algorithm/SerialSend/V_bus'], 'Value'));
motorParam.p = str2double(get_param([hostModelName '/Algorithm/SerialSend/pole_pairs'], 'Value'));
motorParam.nomCurrent =  str2double(get_param([hostModelName '/Algorithm/SerialSend/I_rated'], 'Value'));
motorParam.ratedSpeed =  str2double(get_param([hostModelName '/Algorithm/SerialSend/speed_rated'], 'Value'));
motorParam.PositionOffset =  str2double(get_param([hostModelName '/Algorithm/SerialSend/Position_Offset'], 'Value'));
motorParam.SensorSelection =  str2double(get_param([hostModelName '/Algorithm/SerialSend/Sensor_Selection'], 'Value'));
motorParam.QEPSlits =  str2double(get_param([hostModelName '/Algorithm/SerialSend/qepSlits'], 'Value'));
boardSelection =  str2double(get_param([hostModelName '/boardSelection'], 'Value'));

%% Inverter Parameters
% if isequal(boardSelection,2) || isequal(boardSelection,3)
    Rds_on = 0.85;%0.73;
    Rshunt = 0.33;
    inverter.V_max = 3.3/(9.31/(9.31+169));% (9.31/(9.31+169)) --> Voltage divider gain
    inverter.I_max = 3.2679;
    inverter.R_board = Rds_on+Rshunt;
    set_param([hostModelName '/Host Serial Setup'],'BaudRate', '2e6');
    set_param([hostModelName '/Algorithm/SerialSend/Data_Conditioning_Tx'],'LabelModeActiveChoice','Floating_Point_Target');
    set_param([hostModelName '/Algorithm/SerialReceive'],'LabelModeActiveChoice','Floating_Point_Target');
% end
assignin('base', 'inverter', inverter);
assignin('base', 'simTime', simTime);
assignin('base', 'motorParam', motorParam);

if str2double(get_param([hostModelName '/Algorithm/UserInput/BoardSel'], 'Value')) == 2
    CPU_frequency = 170e6; %(Hz);
else
    CPU_frequency = 84e6; %(Hz);
end
assignin('base', 'CPU_frequency', CPU_frequency);

%% PWM Settings

if isequal(boardSelection,2) || isequal(boardSelection,3)
    PWM_frequency = 10e3; %(Hz);
else
	PWM_frequency = 20e3; %(Hz);
end
Ts = 1/PWM_frequency;
assignin('base', 'Ts', Ts);
PWM_Counter_Period = round(CPU_frequency/PWM_frequency/2); %(PWM timer counts);
assignin('base', 'PWM_Counter_Period', PWM_Counter_Period);

% Speed Per Unit Scalar
Speed_per_unit_scaler = motorParam.ratedSpeed; %(+/-1200rpm <=> +/-1 in Q format)
assignin('base', 'Speed_per_unit_scaler', Speed_per_unit_scaler);

%% Controller design
sigma   = evalin('base', get_param([hostModelName '/Algorithm/SerialSend/Overall_Delay'], 'Value'));            % TIC2000   //  Estimated practical delay between duty update and feedback update
assignin('base', 'sigma',sigma);
disp(Ts)
disp(motorParam)
disp(inverter)
disp(sigma)
% LocalWords:  qep scaler
