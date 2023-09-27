cmake_minimum_required(VERSION 3.12)
project(MySFMLProject)

add_executable(MySFMLProject
    ecs/AComponent.cpp
    ecs/Core.cpp
    ecs/Entity.cpp
    ecs/Scene.cpp
    ecs/SceneManager.cpp
    ecs/components/EnemyComponent.cpp
    ecs/components/HealthComponent.cpp
    ecs/components/PlayerComponent.cpp
    ecs/components/PositionComponent.cpp
    ecs/components/RotationComponent.cpp
    ecs/components/ScaleComponent.cpp
    ecs/components/ShootComponent.cpp
    ecs/components/VelocityComponent.cpp
    ecs/system/ASystem.cpp
    ecs/system/AudioSystem.cpp
    ecs/system/EventSystem.cpp
    ecs/system/GameSystem.cpp
    ecs/system/GraphicSystem.cpp
    ecs/system/ParticleSystem.cpp
    main.cpp
)

target_include_directories(MySFMLProject PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/ecs/ ${CMAKE_CURRENT_SOURCE_DIR}/ecs/system/ ${CMAKE_CURRENT_SOURCE_DIR}/ecs/components/)

