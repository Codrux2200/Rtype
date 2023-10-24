/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PositionComponent
*/

#include <iostream>
#include "PositionComponent.hpp"

ECS::PositionComponent::PositionComponent(float x, float y)
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

void ECS::PositionComponent::move(float x, float y)
{
    _x += x;
    _y += y;

    std::cout << "x: " << _x << " y: " << _y << std::endl;
}
