cmake_minimum_required(VERSION 3.11)
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
        Network/data/StartData.hpp
        Network/data/DisconnectData.hpp
        Network/data/DeadData.hpp
        Network/data/EntitySpawnData.hpp
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
        ecs/system/GameSystem.cpp
        ecs/system/GameSystem.hpp
        ecs/components/PositionComponent.cpp
        ecs/components/PositionComponent.hpp
        ecs/components/RotationComponent.cpp
        ecs/components/RotationComponent.hpp
        ecs/components/ScaleComponent.cpp
        ecs/components/ScaleComponent.hpp
        ecs/components/AGameComponent.hpp
        ecs/components/PlayerBulletComponent.cpp
        ecs/components/PlayerBulletComponent.hpp
)

set(CLIENT_SOURCES ${NETWORK_SOURCES} ${ECS_SOURCES}
        client/main.cpp
        client/Connection.cpp
        client/Connection.hpp
        client/ConvertPath.cpp
        client/ConvertPath.hpp
        client/ecs/Core.hpp
        client/ecs/Core.cpp
        client/ecs/EventSystem.cpp
        client/ecs/EventSystem.hpp
        client/ecs/GraphicSystem.cpp
        client/ecs/AudioSystem.cpp
        client/ecs/AudioSystem.hpp
        client/ecs/GraphicSystem.hpp
        client/ecs/components/BackgroundComponent.cpp
        client/ecs/components/BackgroundComponent.hpp
        client/ecs/components/MusicsComponent.cpp
        client/ecs/components/MusicsComponent.hpp
        client/ecs/components/SoundComponent.cpp
        client/ecs/components/SoundComponent.hpp
        client/ecs/components/ClickComponent.cpp
        client/ecs/components/ClickComponent.hpp
        client/ecs/components/EnemyComponent.cpp
        client/ecs/components/EnemyComponent.hpp
        client/ecs/components/AEventComponent.hpp
        client/ecs/components/ControlComponent.cpp
        client/ecs/components/ControlComponent.hpp
        client/ecs/components/SpriteComponent.cpp
        client/ecs/components/SpriteComponent.hpp
        client/ecs/components/ShootComponent.hpp
        client/ecs/components/ShootComponent.cpp
        client/ecs/models/ButtonEntity.cpp
        client/ecs/models/ButtonEntity.hpp
        client/ecs/components/TextComponent.cpp
        client/ecs/components/TextComponent.hpp
        client/ecs/models/EnemyEntity.cpp
        client/ecs/models/EnemyEntity.hpp
        client/ecs/models/PlayerBullet.cpp
        client/ecs/models/PlayerBullet.hpp
        client/ecs/models/PlayerEntity.cpp
        client/ecs/models/PlayerEntity.hpp
)

set(SERVER_SOURCES ${NETWORK_SOURCES} ${ECS_SOURCES}
        server/main.cpp
        server/Server.cpp
        server/Server.hpp
        server/Client.cpp
        server/Client.hpp
        server/ClientManager.cpp
        server/ClientManager.hpp
        server/ServerCore.cpp
        server/ServerCore.hpp
        server/ecs/components/HitboxComponent.cpp
        server/ecs/components/HitboxComponent.hpp
        server/ecs/components/EnemyComponent.cpp
        server/ecs/components/EnemyComponent.hpp
        server/ecs/components/PlayerComponent.cpp
        server/ecs/components/PlayerComponent.hpp
        server/ecs/CollisionSystem.cpp
        server/ecs/CollisionSystem.hpp
        server/ecs/models/PlayerEntity.cpp
        server/ecs/models/PlayerEntity.hpp
        server/ecs/models/EnemyEntity.cpp
        server/ecs/models/EnemyEntity.hpp
        server/ecs/models/PlayerBullet.cpp
        server/ecs/models/PlayerBullet.hpp
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
        client/ecs/models
)

# Ajoutez les sous-modules SFML et Boost.Asio comme sous-répertoires
target_include_directories(rtype-server PRIVATE
        ${Boost_INCLUDE_DIRS}
        ${ECS_INCLUDE}
        ${NETWORK_INCLUDE}
        server/ecs
        server/ecs/models
        server/ecs/components
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
