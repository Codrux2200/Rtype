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
    this->x = x;
    this->y = y;
}

ECS::PositionComponent::~PositionComponent()
{
}

void ECS::PositionComponent::setValue(std::vector<int> values)
{
    if (values.size() != 2) {
        return;
    }
    x = values[0];
    y = values[1];
}

std::vector<int> ECS::PositionComponent::getValue() const
{
    std::vector<int> position = std::vector<int>();
    position.push_back(x);
    position.push_back(y);
    return position;
}

std::shared_ptr<ECS::IComponent> ECS::PositionComponent::clone() const
{
    return std::make_shared<ECS::PositionComponent>(x, y);
}

void ECS::PositionComponent::move(float x, float y)
{
    x += x;
    y += y;
}
