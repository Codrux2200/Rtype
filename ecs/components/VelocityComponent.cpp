/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** VelocityComponent
*/

#include <iostream>
#include "VelocityComponent.hpp"

ECS::VelocityComponent::VelocityComponent()
{
    _velocity = 0;
}

ECS::VelocityComponent::~VelocityComponent()
{
}

void ECS::VelocityComponent::setValue(std::vector<int> values)
{
    if (values.size() != 1) {
        std::cerr << "Error: setValue in VelocityComponent" << std::endl;
        return;
    }
    _velocity = values[0];
}

std::vector<int> ECS::VelocityComponent::getValue() const
{
    std::vector<int> velocity = std::vector<int>();
    velocity.push_back(_velocity);
    return velocity;
}
