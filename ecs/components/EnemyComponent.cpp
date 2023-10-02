/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"

ECS::EnemyComponent::EnemyComponent(int uid)
    : AComponent(uid)
{
}

ECS::EnemyComponent::~EnemyComponent()
{
}

void ECS::EnemyComponent::setValue(int enemy, int unused)
{
}

std::vector<int> ECS::EnemyComponent::getValue() const
{
    std::vector<int> enemy = std::vector<int>();
    return enemy;
}
