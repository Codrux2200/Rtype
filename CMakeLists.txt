cmake_minimum_required(VERSION 3.12)
project(MySFMLProject)

set(CMAKE_TOOLCHAIN_FILE "chemin/vers/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

find_package(asio REQUIRED)

add_executable(MySFMLProject main.cpp)

target_include_directories(MySFMLProject PRIVATE ${SFML_INCLUDE_DIRS} ${ASIO_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/ecs/system)

target_link_libraries(MySFMLProject PRIVATE sfml-system sfml-window sfml-graphics asio)
