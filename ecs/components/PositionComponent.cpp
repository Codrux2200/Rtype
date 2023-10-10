/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PositionComponent
*/

#include "PositionComponent.hpp"

ECS::PositionComponent::PositionComponent(int x, int y, int uid, bool keymoved)
{
    _uid = uid;
    _x = x;
    _y = y;
    _keymoved = keymoved;
}

ECS::PositionComponent::~PositionComponent()
{
}

void ECS::PositionComponent::setValue(int x, int y)
{
    _x = x;
    _y = y;
}

std::vector<int> ECS::PositionComponent::getValue() const
{
    std::vector<int> position = std::vector<int>();
    position.push_back(_x);
    position.push_back(_y);
    return position;
}