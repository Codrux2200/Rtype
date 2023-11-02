/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootComponent
*/

#include "BossShootComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

namespace ECS {

    std::shared_ptr<IComponent> BossShootComponent::clone() const
    {
        return std::make_shared<BossShootComponent>();
    }

    void BossShootComponent::update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();
        auto velocityComponent = entity.getComponent<VelocityComponent>();

        if (positionComponent == nullptr || velocityComponent == nullptr)
            return;

        positionComponent->x += velocityComponent->vx * deltaTime;
        positionComponent->y += velocityComponent->vy * deltaTime;

        if (positionComponent->x < -100) {
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }
    }
}