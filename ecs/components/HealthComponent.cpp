/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HealthComponent
*/

#include <iostream>
#include "HealthComponent.hpp"

ECS::HealthComponent::HealthComponent(int health)
{
    _health = health;
}

ECS::HealthComponent::~HealthComponent()
{
}

void ECS::HealthComponent::setValue(std::vector<int> values)
{
    if (values.size() != 1) {
        std::cerr << "Error: setValue in HealthComponent" << std::endl;
        return;
    }
    _health = values[0];
}

std::vector<int> ECS::HealthComponent::getValue() const
{
    std::vector<int> health = std::vector<int>();
    health.push_back(_health);
    return health;
}
