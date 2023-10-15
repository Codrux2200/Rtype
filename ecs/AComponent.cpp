/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AComponent
*/

#include <iostream>
#include "AComponent.hpp"

void ECS::AComponent::setValue(std::vector<int> values)
{
    std::cout << "setValue not implemented" << std::endl;
}

std::vector<int> ECS::AComponent::getValue() const
{
    std::cout << "getValue not implemented" << std::endl;
    return std::vector<int>();
}

void ECS::AComponent::setEnabled(bool enabled)
{
    _isEnabled = enabled;
}

bool ECS::AComponent::isEnabled() const
{
    return _isEnabled;
}

ECS::ComponentType ECS::AComponent::getType() const
{
    return _type;
}
