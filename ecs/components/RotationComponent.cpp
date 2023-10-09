/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** RotationComponent
*/

#include "RotationComponent.hpp"

ECS::RotationComponent::RotationComponent(int uid)
    : AComponent(uid)
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

void ECS::RotationComponent::setValue(int rotation, int unused)
{
    _rotation = rotation;
}