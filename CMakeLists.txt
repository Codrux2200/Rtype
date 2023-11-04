cmake_minimum_required(VERSION 3.15)
project(RType)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CLIENT_BINARY "rtype-client")
set(SERVER_BINARY "rtype-server")

# -- Fetch Boost
include(FetchContent)

if(APPLE)
    find_package(ICU REQUIRED COMPONENTS uc i18n)    
endif(APPLE)


FetchContent_Declare(
    Boost
    URL "https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.tar.xz"
    DOWNLOAD_NAME "boost_1_83_0.tar.gz"
    DOWNLOAD_NO_PROGRESS TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DCONFIG=Release
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(BOOST_RUNTIME_LINK static)
set(BOOST_INCLUDE_LIBRARIES
    asio
    assert
    align
    array

    bind

    coroutine
    config
    context
    core
    chrono

    date_time

    exception

    function
    filesystem

    move

    system
    smart_ptr

    throw_exception
    type_traits

    utility
)
FetchContent_MakeAvailable(Boost)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")

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
        Network/data/BossStateData.hpp
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
        ecs/components/VelocityComponent.cpp
        ecs/components/VelocityComponent.hpp
        ecs/components/BossShootComponent.cpp
        ecs/components/BossShootComponent.hpp
        ecs/components/VelocityComponent.cpp
        ecs/components/VelocityComponent.hpp
        ecs/components/HealthComponent.cpp
        ecs/components/HealthComponent.hpp
        ecs/components/EnemyBulletComponent.cpp
        ecs/components/EnemyBulletComponent.hpp
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
        client/ecs/components/PlayerBulletComponent.cpp
        client/ecs/components/PlayerBulletComponent.hpp
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
        client/ecs/components/BossComponent.cpp
        client/ecs/components/BossComponent.hpp
        client/ecs/components/TextComponent.cpp
        client/ecs/components/TextComponent.hpp
        client/ecs/components/BossLaserEyeComponent.cpp
        client/ecs/components/BossLaserEyeComponent.hpp
        client/ecs/components/BossLaserMouthComponent.cpp
        client/ecs/components/BossLaserMouthComponent.hpp
        client/ecs/models/ButtonEntity.cpp
        client/ecs/models/ButtonEntity.hpp
        client/ecs/models/EnemyEntity.cpp
        client/ecs/models/EnemyEntity.hpp
        client/ecs/models/PlayerBullet.cpp
        client/ecs/models/PlayerBullet.hpp
        client/ecs/models/PlayerEntity.cpp
        client/ecs/models/PlayerEntity.hpp
        client/ecs/models/Boss/BossEntity.cpp
        client/ecs/models/Boss/BossEntity.hpp
        client/ecs/models/Boss/BossShootEntity.cpp
        client/ecs/models/Boss/BossShootEntity.hpp
        client/ecs/models/Boss/BossEyesLaserEntity.cpp
        client/ecs/models/Boss/BossEyesLaserEntity.hpp
        client/ecs/models/Boss/BossMouthLaserEntity.cpp
        client/ecs/models/Boss/BossMouthLaserEntity.hpp
        client/ecs/models/StaticBackgroundEntity.cpp
        client/ecs/models/StaticBackgroundEntity.hpp
        client/ecs/components/ScoreBoardComponent.cpp
        client/ecs/components/ScoreBoardComponent.hpp
)

set(SERVER_SOURCES ${NETWORK_SOURCES} ${ECS_SOURCES}
        server/main.cpp
        server/Server.cpp
        server/Server.hpp
        server/Client.cpp
        server/Client.hpp
        server/ClientManager.cpp
        server/ClientManager.hpp
        server/ecs/WaveSystem.cpp
        server/ecs/WaveSystem.hpp
        server/ServerCore.cpp
        server/ServerCore.hpp
        server/ecs/components/HitboxComponent.cpp
        server/ecs/components/HitboxComponent.hpp
        server/ecs/components/EnemyComponent.cpp
        server/ecs/components/EnemyComponent.hpp
        server/ecs/components/PlayerComponent.cpp
        server/ecs/components/PlayerBulletComponent.cpp
        server/ecs/components/PlayerBulletComponent.hpp
        server/ecs/components/PlayerComponent.hpp
        server/ecs/components/BossComponent.cpp
        server/ecs/components/BossComponent.hpp
        server/ecs/CollisionSystem.cpp
        server/ecs/CollisionSystem.hpp
        server/ecs/models/PlayerEntity.cpp
        server/ecs/models/PlayerEntity.hpp
        server/ecs/models/EnemyEntity.cpp
        server/ecs/models/EnemyEntity.hpp
        server/ecs/models/PlayerBullet.cpp
        server/ecs/models/PlayerBullet.hpp
        server/ecs/models/BossEntity.cpp
        server/ecs/models/BossEntity.hpp
        server/ecs/models/BossShootEntity.cpp
        server/ecs/models/BossShootEntity.hpp
        server/ecs/models/EnemyBullet.cpp
        server/ecs/models/EnemyBullet.hpp
)


FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
)

# Print SFML Include and Lib directories
message(STATUS "SFML Include: ${SFML_SOURCE_DIR}/include")

FetchContent_MakeAvailable(SFML)


# Ajoutez vos sources existantes à votre exécutable
add_executable(${CLIENT_BINARY} ${CLIENT_SOURCES})

# Ajoutez vos sources existantes à votre exécutable
add_executable(${SERVER_BINARY} ${SERVER_SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(
    ${CLIENT_BINARY}
    PRIVATE
        Threads::Threads
)

target_link_libraries(
    ${SERVER_BINARY}
    PRIVATE
        Threads::Threads
)

foreach(lib ${BOOST_INCLUDE_LIBRARIES})
    target_link_libraries(
        ${CLIENT_BINARY}
        PRIVATE
        Boost::${lib}
    )
    target_include_directories(
        ${CLIENT_BINARY}
        PRIVATE
        Boost::${lib}
    )
    target_link_libraries(
        ${SERVER_BINARY}
        PRIVATE
        Boost::${lib}
    )
    target_include_directories(
        ${SERVER_BINARY}
        PRIVATE
        Boost::${lib}
    )
endforeach()

# Ajoutez les répertoires d'inclusion de vos composants ECS
target_include_directories(${CLIENT_BINARY} PRIVATE
        ${ECS_INCLUDE}
        ${NETWORK_INCLUDE}
        ${SFML_SOURCE_DIR}/include
        client
        client/ecs
        client/ecs/components
        client/ecs/models
)

# Ajoutez les sous-modules SFML et Boost.Asio comme sous-répertoires
target_include_directories(${SERVER_BINARY} PRIVATE
        ${ECS_INCLUDE}
        ${NETWORK_INCLUDE}
        server/ecs
        server/ecs/models
        server/ecs/components
)

# Liens vers les bibliothèques SFML et Boost.Asio
target_link_libraries(${CLIENT_BINARY}
        PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)