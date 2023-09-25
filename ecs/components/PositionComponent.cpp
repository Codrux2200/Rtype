/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PositionComponent
*/

#include "PositionComponent.hpp"

ECS::PositionComponent::PositionComponent(int x, int y, int uid)
    : AComponent(uid)
{
    _x = x;
    _y = y;
}

ECS::PositionComponent::~PositionComponent()
{
}

int ECS::PositionComponent::getX() const
{
    return _x;
}

int ECS::PositionComponent::getY() const
{
    return _y;
}

void ECS::PositionComponent::setX(int x)
{
    _x = x;
}

void ECS::PositionComponent::setY(int y)
{
    _y = y;
}