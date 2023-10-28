/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "PositionComponent.hpp"
#include "EnemyComponent.hpp"

std::shared_ptr<ECS::IComponent> ECS::EnemyComponent::clone() const
{
    return std::make_shared<ECS::EnemyComponent>();
}
