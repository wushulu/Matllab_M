%Invert%
Invert.gian = 5;
Invert.Rs   = 0.047;
Invert.refe_volts = 1.65;
Invert.volts       = 3.3;
Invert.Max_current = Invert.refe_volts/(Invert.gian*Invert.Rs);

fprintf('%3.2f',Invert.Max_current);