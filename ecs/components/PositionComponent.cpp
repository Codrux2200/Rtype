/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PositionComponent
*/

#include <iostream>
#include "PositionComponent.hpp"

namespace ECS {
    PositionComponent::PositionComponent()
    {
        x = 0;
        y = 0;
    }

    PositionComponent::PositionComponent(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    PositionComponent::~PositionComponent()
    {
    }

    void PositionComponent::setValue(std::vector<int> values)
    {
        if (values.size() != 2) {
            return;
        }
        x = values[0];
        y = values[1];
    }

    std::vector<int> PositionComponent::getValue() const
    {
        std::vector<int> position = std::vector<int>();
        position.push_back(x);
        position.push_back(y);
        return position;
    }

    std::shared_ptr<IComponent> PositionComponent::clone() const
    {
        return std::make_shared<PositionComponent>(x, y);
    }

    void PositionComponent::move(float x, float y)
    {
        this->x += x;
        this->y += y;
    }
}
