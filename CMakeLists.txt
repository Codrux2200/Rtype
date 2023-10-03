cmake_minimum_required(VERSION 3.22.1)
set(PROJECT_NAME UDPserver)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

find_package(Boost REQUIRED)

set(NETWORK_SOURCES
    Network/Packet.hpp
    Network/Status.hpp
    Network/PacketManager.hpp
    Network/PacketManager.cpp
    Network/data/HubData.hpp
    Network/data/StartData.hpp
)

set(CLIENT_SOURCES
    client/Connection.hpp
    client/Connection.cpp
    client/main.cpp
    )

set(SERVER_SOURCES
    server/Server.hpp
    server/Server.cpp
    server/main.cpp
    server/Client.hpp
    server/Client.cpp
)

add_executable(server ${NETWORK_SOURCES} ${SERVER_SOURCES})
add_executable(client ${NETWORK_SOURCES} ${CLIENT_SOURCES})

target_include_directories(server PRIVATE ${Boost_INCLUDE_DIRS} Network Network/data)
target_link_libraries(server ${Boost_LIBRARIES})

target_include_directories(client PRIVATE ${Boost_INCLUDE_DIRS} Network Network/data)
target_link_libraries(client ${Boost_LIBRARIES})
