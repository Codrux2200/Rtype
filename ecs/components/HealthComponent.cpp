/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HealthComponent
*/

#include "HealthComponent.hpp"

ECS::HealthComponent::HealthComponent(int uid)
    : AComponent(uid)
{
    _health = 100;
}

ECS::HealthComponent::~HealthComponent()
{
}

void ECS::HealthComponent::setHealth(int health)
{
    _health = health;
}

int ECS::HealthComponent::getHealth() const
{
    return _health;
}