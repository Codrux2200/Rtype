cmake_minimum_required(VERSION 3.12)
project(MySFMLProject)
include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.5.1
)

FetchContent_MakeAvailable(SFML)
FetchContent_Declare(
  Asio
  GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
  GIT_TAG        master  # Vous pouvez spécifier une version spécifique si nécessaire
)

FetchContent_MakeAvailable(Asio)
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

target_include_directories(MySFMLProject PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/ecs/system/)

target_link_libraries(MySFMLProject PRIVATE sfml-system sfml-window sfml-graphics)
