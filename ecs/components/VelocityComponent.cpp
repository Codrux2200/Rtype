/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** VelocityComponent
*/

#include "VelocityComponent.hpp"

ECS::VelocityComponent::VelocityComponent()
{
    _velocity = 0;
}

ECS::VelocityComponent::~VelocityComponent()
{
}

void ECS::VelocityComponent::setValue(int velocity, int unused)
{
    _velocity = velocity;
}

std::vector<int> ECS::VelocityComponent::getValue() const
{
    std::vector<int> velocity = std::vector<int>();
    velocity.push_back(_velocity);
    return velocity;
}
