cmake_minimum_required(VERSION 3.12)
project(MyNetworkProject)

add_executable(MyNetworkProject
    Network/network.cpp
    Network/networkModule.cpp
    Network/ThreadSafeList.cpp
    main.cpp
)

target_include_directories(MyNetworkProject PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MyNetworkProject)
