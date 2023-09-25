if ! [ -d "vcpkg" ]; then
  git clone https://github.com/microsoft/vcpkg.git
  cd vcpkg
  ./bootstrap-vcpkg.sh
  ./vcpkg integrate install
  cd ..
fi

if ! [ -x "$(command -v cmake)" ]; then
  echo "CMake n'est pas installé, installation en cours..."
  wget https://github.com/Kitware/CMake/releases/download/v3.22.0/cmake-3.22.0-Linux-x86_64.sh
  chmod +x cmake-3.22.0-Linux-x86_64.sh
  ./cmake-3.22.0-Linux-x86_64.sh --skip-license --prefix=/usr/local
  rm cmake-3.22.0-Linux-x86_64.sh
  echo "CMake est maintenant installé."
fi

./vcpkg/vcpkg install sfml
./vcpkg/vcpkg install boost-asio

mkdir -p build
cd build

cmake -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" ..
cmake --build .
