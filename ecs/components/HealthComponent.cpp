/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HealthComponent
*/

#include "HealthComponent.hpp"

ECS::HealthComponent::HealthComponent(int health)
{
    _health = health;
}

ECS::HealthComponent::~HealthComponent()
{
}

void ECS::HealthComponent::setValue(int health, int unused)
{
    _health = health;
}

std::vector<int> ECS::HealthComponent::getValue() const
{
    std::vector<int> health = std::vector<int>();
    health.push_back(_health);
    return health;
}
