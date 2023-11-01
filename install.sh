#!/bin/bash

detect_package_manager() {
  if [ -x "$(command -v apt-get)" ]; then
    echo "apt-get"
  elif [ -x "$(command -v yum)" ]; then
    echo "yum"
  elif [ -x "$(command -v brew)" ]; then
    echo "brew"
  elif [ -x "$(command -v pacman)" ]; then
    echo "pacman"
  elif [ -x "$(command -v apk)" ]; then
    echo "apk"
  else
    echo "none"
  fi
}

package_manager=$(detect_package_manager)

install_apt() {
    sudo apt-get update
    sudo apt-get install g++
    sudo apt install libgl1-mesa-dev libgdiplus libfreetype6-dev libopenal-dev libflac-dev libvorbis-dev libvorbisfile3 libvorbisenc2 libogg-dev libudev-dev  libxrandr-dev libxcursor-dev
}

install_yum() {
    sudo yum update
    sudo yum install g++
    sudo dnf install mesa-libGL-devel libgdiplus freetype-devel openal-soft-devel flac-devel libvorbis-devel libogg-devel libudev-devel libXcursor-devel libXrandr-devel mesa-libGLw freetype-devel openal-soft-devel flac-devel
    sudo yum install freeglut-devel systemd-devel
}

install_pacman() {
    sudo pacman -S g++ --noconfirm
    sudo pacman -S mesa lib32-mesa wine-staging winetricks gdiplus freetype2 openal flac libvorbis libvorbisfile libvorbisenc libogg wine-mono wine-gecko libudev --noconfirm

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
        echo "$ID Distribution non prise en charge."
        exit 1
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo "macOS ne nécessite aucune installation spécifique."
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
elif [ "$package_manager" == "pacman" ]; then
  echo "Pacman détecté, installation de CMake..."
  sudo pacman -Sy cmake --noconfirm
  echo "CMake est maintenant installé."
elif [ "$package_manager" == "apk" ]; then
  echo "APK détecté, installation de CMake..."
  sudo apk add cmake
  echo "CMake est maintenant installé."
else
  echo "Aucun gestionnaire de paquets pris en charge n'a été détecté. Veuillez installer CMake manuellement."
  exit 1
fi


cmake . .

chmod -R 777 _deps

cmake --build . -- -j 6