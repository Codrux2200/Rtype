/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** VelocityComponent
*/

#include "VelocityComponent.hpp"

ECS::VelocityComponent::VelocityComponent(int uid)
    : AComponent(uid)
{
}

ECS::VelocityComponent::~VelocityComponent()
{
}

void ECS::VelocityComponent::setVelocity(int velocity)
{
    _velocity = velocity;
}

int ECS::VelocityComponent::getVelocity() const
{
    return _velocity;
}