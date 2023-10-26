/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"

namespace ECS {
    EnemyComponent::EnemyComponent()
    {
    }

    std::shared_ptr<ECS::IComponent> EnemyComponent::clone() const
    {
        return std::make_shared<EnemyComponent>();
    }
}