if ! [ -x "$(command -v cmake)" ]; then
  echo "CMake n'est pas installé, installation en cours..."
  curl -l https://github.com/Kitware/CMake/releases/download/v3.22.0/cmake-3.22.0-Linux-x86_64.sh
  chmod +x cmake-3.22.0-Linux-x86_64.sh
  ./cmake-3.22.0-Linux-x86_64.sh --skip-license --prefix=/usr/local
  rm cmake-3.22.0-Linux-x86_64.sh
  echo "CMake est maintenant installé."
fi


cmake . .
cmake --build .
