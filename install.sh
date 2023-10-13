#!/bin/bash

detect_package_manager() {
  if [ -x "$(command -v apt-get)" ]; then
    package_manager="apt-get"
  elif [ -x "$(command -v yum)" ]; then
    package_manager="yum"
  elif [ -x "$(command -v brew)" ]; then
    package_manager="brew"
  else
    package_manager="none"
  fi
  echo "$package_manager"
}
package_manager=$(detect_package_manager)

#!/bin/bash

# Fonction pour installer des paquets avec le gestionnaire de paquets apt
install_apt() {
    sudo apt-get update
    sudo apt-get install libx11-dev libxrandr-dev libxcursor-dev
    sudo apt-get install -y libflac-dev libvorbis0 libvorbis-dev libx11-6 libxorg1-dev libflac-dev libudev-dev libxcursor-dev libxrandr-dev libopenal-dev
    sudo apt-get install -y xorg x11-xserver-utils x11-utils
    sudo apt-get install 'xserver-xorg-*' 'mesa-*' 'libx*' 'libX*' 'fontconfig*'

}

# Fonction pour installer des paquets avec le gestionnaire de paquets yum
install_yum() {
    sudo yum update
    sudo yum install -y libvorbis libX11-devel libXorg-devel flac-devel libudev-devel libXcursor-devel libXrandr-devel libopenal-dev
    sudo yum groupinstall -y "X Window System"
    sudo yum install 'xorg-x11-*' 'mesa-*' 'libX*' 'fontconfig*'
    sudo yum install libX11-devel libXrandr-devel libXcursor-devel
}

# Fonction pour installer des paquets avec le gestionnaire de paquets pacman
install_pacman() {
    sudo pacman -Syu --noconfirm libvorbis libx11 libxorg flac libudev libxcursor libxrandr xorg-server xorg-xrandr xorg-xset libopenal-dev
    sudo pacman -Syyu --overwrite '*' 'xorg-*' 'mesa-*' 'libx*' 'libX*' 'fontconfig*'
    sudo pacman -S libx11 libxrandr libxcursor

}

# Détecter la distribution
if [[ -e /etc/os-release ]]; then
    source /etc/os-release
    if [[ "$ID" == "debian" || "$ID" == "ubuntu" || "$ID" == "pop" ]]; then
        install_apt
    elif [[ "$ID" == "fedora" || "$ID" == "centos" || "$ID" == "rhel" ]]; then
        install_yum
    elif [[ "$ID" == "arch" || "$ID" == "manjaro" ]]; then
        install_pacman
    else
        echo "Distribution non prise en charge: $ID"
        exit 1
    fi
else
    echo "Impossible de détecter la distribution."
    exit 1
fi




if [ "$package_manager" == "apt-get" ]; then
  echo "APT détecté, installation de CMake..."
  sudo apt-get update
  sudo apt-get install cmake
  echo "CMake est maintenant installé."
elif [ "$package_manager" == "yum" ]; then
  echo "YUM détecté, installation de CMake..."
  sudo yum install cmake
  echo "CMake est maintenant installé."
elif [ "$package_manager" == "brew" ]; then
  echo "Homebrew détecté, installation de CMake..."
  brew install cmake
  echo "CMake est maintenant installé."
else
  echo "Aucun gestionnaire de paquets pris en charge n'a été détecté. Veuillez installer CMake manuellement."
  exit 1
fi



cmake . .
cmake --build .

sudo rm -fr _deps
