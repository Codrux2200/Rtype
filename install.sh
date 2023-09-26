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

