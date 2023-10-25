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
    return {};
}

ECS::ComponentType ECS::AComponent::getType() const
{
    return _type;
}
