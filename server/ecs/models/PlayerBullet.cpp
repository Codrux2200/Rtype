/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBullet
*/

#include "PlayerBullet.hpp"
#include "BossComponent.hpp"
#include "DeadData.hpp"
#include "EnemyComponent.hpp"
#include "HitboxComponent.hpp"
#include "PacketManager.hpp"
#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

namespace ECS {
    PlayerBullet::PlayerBullet(int id) : Entity(id)
    {
        addComponent(std::make_shared<PositionComponent>(0, 0));
        addComponent(std::make_shared<PlayerBulletComponent>());
        addComponent(std::make_shared<HitboxComponent>(
        std::bind(&PlayerBullet::_callbackPlayerBulletHit, this,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
        std::vector<std::pair<int, int>> {{0, 0}, {50, 17}}));
        addComponent(std::make_shared<VelocityComponent>(400, 0));
        updateGameComponents();
    }

    void PlayerBullet::_callbackPlayerBulletHit(
    std::shared_ptr<Entity> self, std::shared_ptr<Entity> other,
    std::vector<Network::Packet> & packets)
    {
        if (other == nullptr || self == nullptr)
            return;

        Network::data::DeathReason deathReason;

        if (other->getComponent<EnemyComponent>() != nullptr)
            deathReason = Network::data::DeathReason::ENEMY;
        else if (other->getComponent<BossComponent>() != nullptr)
            deathReason = Network::data::DeathReason::BOSS;
        else
            return;

        self->isEnabled = false;
        self->deathReason = deathReason;

        Network::data::DeadData deadData {self->getId(), deathReason};
        std::unique_ptr<Network::Packet> packet =
        Network::PacketManager::createPacket(
        Network::PacketType::DEAD, &deadData);

        packets.push_back(*packet);
    }
}
