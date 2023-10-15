/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PositionComponent
*/

#include <iostream>
#include "PositionComponent.hpp"

ECS::PositionComponent::PositionComponent(int x, int y)
{
    _x = x;
    _y = y;
}

ECS::PositionComponent::~PositionComponent()
{
}

void ECS::PositionComponent::setValue(std::vector<int> values)
{
    if (values.size() != 2) {
        std::cerr << "Error: setValue in PositionComponent" << std::endl;
        return;
    }
    _x = values[0];
    _y = values[1];
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

void ECS::PositionComponent::move(int x, int y)
{
    _x += x;
    _y += y;
}
