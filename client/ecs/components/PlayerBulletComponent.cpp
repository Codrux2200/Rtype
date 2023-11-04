/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerBulletComponent::clone() const
    {
        return std::make_shared<PlayerBulletComponent>();
    }

    void PlayerBulletComponent::update(
    std::vector<Network::Packet> &packets, Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();
        auto velocityComponent = entity.getComponent<VelocityComponent>();

        if (positionComponent == nullptr || velocityComponent == nullptr)
            return;
        
        positionComponent->x += velocityComponent->vx * deltaTime;
        positionComponent->y += velocityComponent->vy * deltaTime;

        

        //TODO: change to window size
        if (positionComponent->x > 800 + 100) {
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }
    }

    bool PlayerBulletComponent::onDestroy(Entity &entity, Network::data::DeathReason reason, float dt)
    {
        if (reason != Network::data::BOSS)
            return true;
        auto soundComponent = entity.getComponent<SoundComponent>();
        if(Hitinitialize == false) {
            isEnabled = false;
            auto spriteComponent = entity.getComponent<SpriteComponent>();
            if(spriteComponent != nullptr) {
                spriteComponent->isEnabled = false;
            }
            if(soundComponent != nullptr) {
                soundComponent->play("BossHit");
            }
            Hitinitialize = true;
        }
        if(soundComponent != nullptr) {
            if(soundComponent->isPlaying("BossHit") == false) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
}