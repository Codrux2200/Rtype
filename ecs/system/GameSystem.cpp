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
    : ASystem(ECS::SystemType::GAME)
{
}

ECS::GameSystem::~GameSystem()
{
}
