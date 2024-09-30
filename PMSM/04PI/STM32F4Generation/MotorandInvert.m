%Invert%
Invert.gian = 5;
Invert.Rs   = 0.047;
Invert.refe_volts = 1.65;
Invert.MCU_volts       = 3.30;
Invert.Max_current = Invert.refe_volts/(Invert.gian*Invert.Rs);

fprintf('%3.2f',Invert.Max_current);
disp(Invert.Max_current);