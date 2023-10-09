/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ScaleComponent
*/

#include "ScaleComponent.hpp"

ECS::ScaleComponent::ScaleComponent(int x, int y, int uid)
{
    _uid = uid;
    _x = x;
    _y = y;
}

ECS::ScaleComponent::~ScaleComponent()
{
}

void ECS::ScaleComponent::setValue(int x, int y)
{
    _x = x;
    _y = y;
}

std::vector<int> ECS::ScaleComponent::getValue() const
{
    std::vector<int> scale = std::vector<int>();
    scale.push_back(_x);
    scale.push_back(_y);
    return scale;
}
