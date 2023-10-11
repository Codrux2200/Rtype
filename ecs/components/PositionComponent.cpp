/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PositionComponent
*/

#include "PositionComponent.hpp"

ECS::PositionComponent::PositionComponent(int x, int y)
{
    _x = x;
    _y = y;
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

std::shared_ptr<ECS::IComponent> ECS::PositionComponent::clone() const
{
    return std::make_shared<ECS::PositionComponent>(_x, _y);
}
