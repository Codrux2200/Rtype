/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GameSystem
*/

#include "GameSystem.hpp"
#include <iostream>
#include "HealthComponent.hpp"

ECS::GameSystem::GameSystem()
{
    typeSystem = ECS::SystemType::GAME;
}

ECS::GameSystem::~GameSystem()
{
}

void ECS::GameSystem::update(
    SceneManager &sceneManager, const SceneType &SceneType, const float &deltaTime)
{
    ECS::Scene &scene = sceneManager.getScene(SceneType);

    
}