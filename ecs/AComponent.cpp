/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AComponent
*/

#include "AComponent.hpp"

void ECS::AComponent::setValue(int value, int unused)
{
}

std::vector<int> ECS::AComponent::getValue() const
{
    std::vector<int> value = std::vector<int>();
    return value;
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
