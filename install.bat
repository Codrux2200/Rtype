@echo off

choco -? >nul 2>&1
if %errorlevel% neq 0 (
    echo Chocolatey n'est pas installé. Installation en cours...
    @"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
    if %errorlevel% neq 0 goto install_failed
) else (
    echo Chocolatey est déjà installé.
)

cmake --version >nul 2>&1
if %errorlevel% neq 0 (
    echo CMake n'est pas installé. Installation en cours...
    choco install -y cmake
    if %errorlevel% neq 0 goto install_failed
) else (
    echo CMake est déjà installé.
)

git --version >nul 2>&1
if %errorlevel% neq 0 (
    echo Git n'est pas installé. Installation en cours...
    choco install -y git
    if %errorlevel% neq 0 goto install_failed
) else (
    echo Git est déjà installé.
)

cmake .

if %errorlevel% neq 0 goto install_failed

echo Configuration de CMake terminée avec succès.

goto end

:install_failed
echo Une erreur s'est produite lors de l'installation ou de la configuration. Vérifiez les erreurs ci-dessus.
exit /b 1

:end
