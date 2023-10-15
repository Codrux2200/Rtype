/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** RotationComponent
*/

#include <iostream>
#include "RotationComponent.hpp"

ECS::RotationComponent::RotationComponent(float rotation) : _rotation(rotation)
{
}

std::vector<float> ECS::RotationComponent::getFloatValue() const
{
    return std::vector<float>{_rotation};
}

void ECS::RotationComponent::setFloatValue(float rotation)
{
    _rotation = rotation;
}

std::shared_ptr<ECS::IComponent> ECS::RotationComponent::clone() const
{
    return std::make_shared<RotationComponent>(_rotation);
}
