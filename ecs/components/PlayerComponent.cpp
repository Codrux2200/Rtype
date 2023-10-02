/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"

ECS::PlayerComponent::PlayerComponent(int uid)
    : AComponent(uid)
{
}

ECS::PlayerComponent::~PlayerComponent()
{
}

void ECS::PlayerComponent::setValue(int player, int unused)
{
}

std::vector<int> ECS::PlayerComponent::getValue() const
{
    std::vector<int> player = std::vector<int>();
    return player;
}
