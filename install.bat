@echo off

net session >nul 2>&1
if %errorlevel% neq 0 (
    echo The script must be launched as administrator.
    exit /b 1
)

for /f %%a in ('wmic cpu get NumberOfCores ^| findstr /r "[0-9]"') do (
    set "cores=%%a"
)

cmake --version >nul 2>&1
if %errorlevel% neq 0 (
    echo CMake not installed, installing...
    winget install -e --id Kitware.CMake
) else (
    echo CMake already installed.
)

git --version >nul 2>&1
if %errorlevel% neq 0 (
    echo Git not installed, installing...
    winget install -e --id Git.Git
) else (
    echo Git already installed.
)

exit
powershell -Command "Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope CurrentUser -Force"

goto end

:install_failed
echo Install failed, check the logs for more information.
exit /b 1

:end
