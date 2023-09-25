/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HitboxComponent
*/

#include "HitboxComponent.hpp"

ECS::HitboxComponent::HitboxComponent(int x, int y, int uid)
    : AComponent(uid)
{
    _x = x;
    _y = y;
}

ECS::HitboxComponent::~HitboxComponent()
{
}

int ECS::HitboxComponent::getX() const
{
    return _x;
}

int ECS::HitboxComponent::getY() const
{
    return _y;
}

void ECS::HitboxComponent::setX(int x)
{
    _x = x;
}

void ECS::HitboxComponent::setY(int y)
{
    _y = y;
}
