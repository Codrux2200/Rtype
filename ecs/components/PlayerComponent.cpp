/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"

ECS::PlayerComponent::PlayerComponent()
{
}

ECS::PlayerComponent::~PlayerComponent()
{
}

void ECS::PlayerComponent::update(const std::vector<int> positions)
{

}

std::shared_ptr<ECS::IComponent> ECS::PlayerComponent::clone() const
{
    return std::make_shared<ECS::PlayerComponent>();
}
