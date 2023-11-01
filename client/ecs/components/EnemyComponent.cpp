/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"
#include "SoundComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> EnemyComponent::clone() const
    {
        return std::make_shared<EnemyComponent>();
    }

    void EnemyComponent::update(std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt)
    {
        auto position = entity.getComponent<PositionComponent>();
        position->x -= _speed * dt;
        if (position->x < 0) {
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }
    }

    bool EnemyComponent::onDestroy(Entity &entity, Network::data::DeathReason reason, float dt)
    {
        if (reason != Network::data::PLAYER_BULLET)
            return true;

        auto sound = entity.getComponent<SoundComponent>();

        if (!sound)
            return true;

        if (!_soundPlayed) {
            sound->play("enemy_death");
            _soundPlayed = true;
        }

        if (sound->isPlaying("enemy_death"))
            return false;
        return true;
    }
}