/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ScaleComponent
*/

#include "ScaleComponent.hpp"

ECS::ScaleComponent::ScaleComponent(int x, int y, int uid)
    : AComponent(uid)
{
    _x = x;
    _y = y;
}

ECS::ScaleComponent::~ScaleComponent()
{
}

int ECS::ScaleComponent::getX() const
{
    return _x;
}

int ECS::ScaleComponent::getY() const
{
    return _y;
}

void ECS::ScaleComponent::setX(int x)
{
    _x = x;
}

void ECS::ScaleComponent::setY(int y)
{
    _y = y;
}
