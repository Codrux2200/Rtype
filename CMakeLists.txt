cmake_minimum_required(VERSION 3.12)
project(MySFMLProject)
include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
)

FetchContent_Declare(
  BoostAsio
  GIT_REPOSITORY https://github.com/boostorg/asio.git
)

# Ajoutez vos sources existantes à votre exécutable
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
    ecs/components/BackgroundComponent.cpp
    ecs/system/ASystem.cpp
    ecs/system/AudioSystem.cpp
    ecs/system/EventSystem.cpp
    ecs/system/GameSystem.cpp
    ecs/system/GraphicSystem.cpp
    ecs/system/ParticleSystem.cpp
    main.cpp
)

# Ajoutez les répertoires d'inclusion de vos composants ECS
target_include_directories(MySFMLProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ecs/
    ${CMAKE_CURRENT_SOURCE_DIR}/ecs/system/
    ${CMAKE_CURRENT_SOURCE_DIR}/ecs/components/
)
FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(BoostAsio)

# Ajoutez les sous-modules SFML et Boost.Asio comme sous-répertoires
target_include_directories(MySFMLProject PRIVATE
    ${SFML_SOURCE_DIR}/include
)


# # Liens vers les bibliothèques SFML
target_link_libraries(MySFMLProject PRIVATE sfml-graphics sfml-audio sfml-network sfml-window sfml-system)