
cd .

if "%1"=="" ("D:\software\MATLAB2024a\bin\win64\gmake"  -f mcb_pmsm_foc_sensorless_nucleo_f401re.mk all) else ("D:\software\MATLAB2024a\bin\win64\gmake"  -f mcb_pmsm_foc_sensorless_nucleo_f401re.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1