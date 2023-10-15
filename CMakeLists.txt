cmake_minimum_required(VERSION 3.12)
project(RType)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")
set(BOOST_INCLUDE_LIBRARIES thread filesystem system asio)
set(BOOST_ENABLE_CMAKE ON)

set(NETWORK_SOURCES
    Network/Packet.hpp
    Network/PacketManager.hpp
    Network/PacketManager.cpp
    Network/PacketType.hpp
    Network/data/ConnectData.hpp
    Network/data/JoinData.hpp
    Network/data/LeaderData.hpp
    Network/data/MoveData.hpp
    Network/data/StartData.hpp
    Network/data/DisconnectData.hpp
)

set(NETWORK_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/Network/
    ${CMAKE_CURRENT_SOURCE_DIR}/Network/data/
)

set(ECS_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/ecs/
    ${CMAKE_CURRENT_SOURCE_DIR}/ecs/system/
    ${CMAKE_CURRENT_SOURCE_DIR}/ecs/components/
)

set(ECS_SOURCES
    ecs/AComponent.cpp
    ecs/AComponent.hpp
    ecs/Entity.cpp
    ecs/Entity.hpp
    ecs/Scene.cpp
    ecs/Scene.hpp
    ecs/SceneManager.cpp
    ecs/SceneManager.hpp
    ecs/EntityFactory.cpp
    ecs/EntityFactory.hpp
    ecs/components/PositionComponent.cpp
    ecs/components/PositionComponent.hpp
    ecs/components/RotationComponent.cpp
    ecs/components/RotationComponent.hpp
    ecs/components/ScaleComponent.cpp
    ecs/components/ScaleComponent.hpp
)

set(CLIENT_SOURCES ${NETWORK_SOURCES} ${ECS_SOURCES}
    client/main.cpp
    client/Connection.cpp
    client/Connection.hpp
    client/ecs/Core.hpp
    client/ecs/Core.cpp
    client/ecs/EventSystem.cpp
    client/ecs/EventSystem.hpp
    client/ecs/GraphicSystem.cpp
    client/ecs/GraphicSystem.hpp
    client/ecs/components/BackgroundComponent.cpp
    client/ecs/components/BackgroundComponent.hpp
    client/ecs/components/ClickComponent.cpp
    client/ecs/components/ClickComponent.hpp
    client/ecs/components/EventComponent.cpp
    client/ecs/components/EventComponent.hpp
    client/ecs/components/PlayerComponent.cpp
    client/ecs/components/PlayerComponent.hpp
    client/ecs/components/SpriteComponent.cpp
    client/ecs/components/SpriteComponent.hpp
)

set(SERVER_SOURCES ${NETWORK_SOURCES} ${ECS_SOURCES}
    server/main.cpp
    server/Server.cpp
    server/Server.hpp
    server/Client.cpp
    server/Client.hpp
    server/ClientManager.cpp
    server/ClientManager.hpp
)


FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
)

FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.80.0
)
FetchContent_MakeAvailable(Boost)

# Print SFML Include and Lib directories
message(STATUS "SFML Include: ${SFML_SOURCE_DIR}/include")

FetchContent_MakeAvailable(SFML)


# Ajoutez vos sources existantes à votre exécutable
add_executable(rtype-client ${CLIENT_SOURCES})

# Ajoutez vos sources existantes à votre exécutable
add_executable(rtype-server ${SERVER_SOURCES})

# Ajoutez les répertoires d'inclusion de vos composants ECS
target_include_directories(rtype-client PRIVATE
    ${ECS_INCLUDE}
    ${NETWORK_INCLUDE}
    ${Boost_INCLUDE_DIRS}
    ${SFML_SOURCE_DIR}/include
    client
    client/ecs
    client/ecs/components
)

# Ajoutez les sous-modules SFML et Boost.Asio comme sous-répertoires
target_include_directories(rtype-server PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${ECS_INCLUDE}
    ${NETWORK_INCLUDE}
)

# Liens vers les bibliothèques SFML et Boost.Asio
target_link_libraries(rtype-client
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    Boost::filesystem
    Boost::array
    Boost::asio
    Boost::system
)

target_link_libraries(rtype-server
    Boost::filesystem
    Boost::array
    Boost::asio
    Boost::system
)
