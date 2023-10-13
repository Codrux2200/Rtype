/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** RotationComponent
*/

#include <iostream>
#include "RotationComponent.hpp"

ECS::RotationComponent::RotationComponent()
{
    _rotation = 0;
}

ECS::RotationComponent::~RotationComponent()
{
}

std::vector<int> ECS::RotationComponent::getValue() const
{
    std::vector<int> rotation = std::vector<int>();
    rotation.push_back(_rotation);
    return rotation;
}

void ECS::RotationComponent::setValue(std::vector<int> values)
{
    if (values.size() != 1) {
        std::cerr << "Error: setValue in RotationComponent" << std::endl;
        return;
    }
    _rotation = values[0];
}
