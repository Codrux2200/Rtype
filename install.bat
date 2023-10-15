@echo off
:: Installation de Chocolatey
if not exist "%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" goto install_powershell
choco -?
if %errorlevel% neq 0 goto install_chocolatey

choco install -y cmake
if %errorlevel% neq 0 goto install_failed

choco install -y git
if %errorlevel% neq 0 goto install_failed

cmake --version
if %errorlevel% neq 0 goto install_failed
cmake <votre_commande_cmake>  :: Remplacez <votre_commande_cmake> par la commande CMake que vous souhaitez exécuter

goto end

:install_powershell
echo PowerShell n'est pas installé. Veuillez l'installer et réessayer.
exit /b 1

:install_chocolatey
echo Chocolatey n'est pas installé. Installation en cours...
@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
if %errorlevel% neq 0 goto install_failed

:install_failed
echo Une erreur s'est produite lors de l'installation. Vérifiez les erreurs ci-dessus.
exit /b 1

:end
