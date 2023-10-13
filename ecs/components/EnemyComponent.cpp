/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"

ECS::EnemyComponent::EnemyComponent()
{
}

ECS::EnemyComponent::~EnemyComponent()
{
}

void ECS::EnemyComponent::update(const std::vector<int> positions)
{
}

std::shared_ptr<ECS::IComponent> ECS::EnemyComponent::clone() const
{
    return std::make_shared<ECS::EnemyComponent>();
}
