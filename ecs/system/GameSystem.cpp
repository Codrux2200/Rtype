/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GameSystem
*/

#include "GameSystem.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"

ECS::GameSystem::GameSystem()
{
    // typeSystem = ECS::SystemType::GAME;
}

ECS::GameSystem::~GameSystem()
{
}

void ECS::GameSystem::update(
    SceneManager &sceneManager, const SceneType &SceneType, const float &deltaTime)
{
}
