/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AComponent
*/

#include "AComponent.hpp"

ECS::AComponent::AComponent(int uid)
{
    _uid = uid;
}

ECS::AComponent::~AComponent()
{
}

void ECS::AComponent::setUid(int uid)
{
    _uid = uid;
}

int ECS::AComponent::getUid() const
{
    return _uid;
}

void ECS::AComponent::setValue(int value, int unused)
{
}

std::vector<int> ECS::AComponent::getValue() const
{
    std::vector<int> value = std::vector<int>();
    return value;
}