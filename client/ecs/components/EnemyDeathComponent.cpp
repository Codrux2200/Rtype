/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyDeathComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> EnemyDeathComponent::clone() const
    {
        return std::make_shared<EnemyDeathComponent>();
    }

    bool EnemyDeathComponent::onDestroy(Entity &entity, Network::data::DeathReason reason, float dt)
    {
        if (reason != Network::data::PLAYER_BULLET)
            return true;

        auto sound = entity.getComponent<SoundComponent>();

        if (!sound)
            return true;

        if (!_soundPlayed) {
            sound->play("enemy_death");
            _soundPlayed = true;
            auto sprite = entity.getComponent<SpriteComponent>();

            if (sprite)
                sprite->isEnabled = false;
        }

        if (sound->isPlaying("enemy_death"))
            return false;
        return true;
    }
    void EnemyDeathComponent::update(std::vector<Network::Packet> &packets, Entity &entity, float deltaTime)
    {
    }
}