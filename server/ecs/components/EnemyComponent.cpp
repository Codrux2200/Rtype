/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"

namespace ECS {
    EnemyComponent::EnemyComponent()
    {
    }

    std::shared_ptr<ECS::IComponent> EnemyComponent::clone() const
    {
        return std::make_shared<EnemyComponent>();
    }

    void EnemyComponent::update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<ECS::PositionComponent>();

        if (positionComponent == nullptr)
            return;

        positionComponent->x -= _speed * deltaTime;
        if (positionComponent->x < 0 - 100) {
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }
    }
}