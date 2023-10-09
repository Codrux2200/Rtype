/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** ASystem
*/

#include "ASystem.hpp"


ECS::ASystem::ASystem(SystemType type)
{
    typeSystem = type;
}

ECS::ASystem::~ASystem()
{
}

void ECS::ASystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime)
{
}