@echo off
setlocal

:: Get the directory where this script is located
set "TARGET_DIR=%~dp0"
:: Remove trailing backslash
set "TARGET_DIR=%TARGET_DIR:~0,-1%"

echo ========================================================
echo CLEANUP SCRIPT
echo Target Directory: "%TARGET_DIR%"
echo ========================================================
echo.
echo WARNING: This will perform the following actions:
echo 1. Delete ALL 'slprj' folders recursively.
echo 2. Delete ALL files EXCEPT: .md, .m, .slx, .ioc, .png, .xlsx
echo 3. Delete empty directories.
echo.
set /p "CONFIRM=Type 'yes' to continue: "

if /i not "%CONFIRM%"=="yes" (
    echo.
    echo Operation cancelled.
    pause
    exit /b
)

echo.
echo Starting cleanup...
echo.

powershell -NoProfile -Command ^
    "$target = '%TARGET_DIR%';" ^
    "$keep = @('.md', '.m', '.slx', '.ioc', '.png', '.xlsx', '.py', '.ps1', '.bat');" ^
    "" ^
    "Write-Host '1. Removing slprj folders...';" ^
    "Get-ChildItem -Path $target -Recurse -Directory -Filter 'slprj' | ForEach-Object { Write-Host 'Deleting slprj: ' $_.FullName; Remove-Item -Path $_.FullName -Recurse -Force };" ^
    "" ^
    "Write-Host '2. Removing unwanted files...';" ^
    "Get-ChildItem -Path $target -Recurse -File | ForEach-Object { if ($keep -notcontains $_.Extension.ToLower()) { Write-Host 'Deleting file: ' $_.FullName; Remove-Item -Path $_.FullName -Force } };" ^
    "" ^
    "Write-Host '3. Removing empty directories...';" ^
    "Get-ChildItem -Path $target -Recurse -Directory | Sort-Object FullName -Descending | ForEach-Object { if ((Get-ChildItem -Path $_.FullName).Count -eq 0) { Write-Host 'Deleting empty dir: ' $_.FullName; Remove-Item -Path $_.FullName -Force } };"

echo.
echo Cleanup complete.
pause
