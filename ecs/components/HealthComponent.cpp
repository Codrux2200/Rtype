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
    this->health = health;
}

std::shared_ptr<ECS::IComponent> ECS::HealthComponent::clone() const
{
    return std::make_shared<HealthComponent>(health);
}
