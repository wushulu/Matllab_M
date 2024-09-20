
set MATLAB=D:\software\Matlab2021a

cd .

if "%1"=="" ("D:\software\Matlab2021a\bin\win64\gmake"  -f add.mk all) else ("D:\software\Matlab2021a\bin\win64\gmake"  -f add.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1