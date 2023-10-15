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

float ECS::RotationComponent::getRotation() const
{
    return _rotation;
}

void ECS::RotationComponent::setRotation(float rotation)
{
    _rotation = rotation;
}