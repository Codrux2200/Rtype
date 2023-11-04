/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ScaleComponent
*/

#include <iostream>
#include "ScaleComponent.hpp"

ECS::ScaleComponent::ScaleComponent(float x, float y) : x(x), y(y)
{
}

std::shared_ptr<ECS::IComponent> ECS::ScaleComponent::clone() const
{
    return std::make_shared<ECS::ScaleComponent>(x, y);
}

std::vector<float> ECS::ScaleComponent::getFloatValue() const
{
    return std::vector<float>{x, y};
}

void ECS::ScaleComponent::setFloatValue(float x, float y)
{
    this->x = x;
    this->y = y;
}
