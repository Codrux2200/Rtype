@echo off
setlocal
@REM test a faire

if exist "%USERPROFILE%\vcpkg" (
    echo vcpkg est déjà installé.
) else (
    git clone https://github.com/microsoft/vcpkg.git %USERPROFILE%\vcpkg
    cd %USERPROFILE%\vcpkg
    bootstrap-vcpkg.bat
)

set VCPKG_ROOT=%USERPROFILE%\vcpkg
set PATH=%VCPKG_ROOT%;%VCPKG_ROOT%\installed\x64-windows\bin;%PATH%

vcpkg install cmake asio sfml

if %ERRORLEVEL% neq 0 (
    echo Erreur lors de l'installation des packages.
    exit /b %ERRORLEVEL%
)

cd Chemin\Vers\Votre\Projet
cmake -B build -S .
cmake --build build

endlocal
