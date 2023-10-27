/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerBulletComponent::clone() const
    {
        return std::make_shared<PlayerBulletComponent>();
    }

    void PlayerBulletComponent::update(
    std::vector<Network::Packet> &packets, Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            return;
        
        positionComponent->x += speed * deltaTime;

        //TODO: change to window size
        if (positionComponent->x > 800 + 100) {
            entity.toDestroy = true;
        }
    }
}