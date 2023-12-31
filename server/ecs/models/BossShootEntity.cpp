/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootEntity
*/

#include "BossShootEntity.hpp"
#include "BossShootComponent.hpp"
#include "HitboxComponent.hpp"
#include "PacketManager.hpp"
#include "PlayerComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

namespace ECS {

    BossShootEntity::BossShootEntity(int id, float vx, float vy) : Entity(id)
    {
        addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
        addComponent(std::make_shared<ECS::BossShootComponent>());
        addComponent(std::make_shared<ECS::VelocityComponent>(vx, vy));
        addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&ECS::BossShootEntity::_callbackBossShootHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
        std::vector<std::pair<int, int>>{{0, 0}, {80, 60}}));
        updateGameComponents();
    }

    void BossShootEntity::_callbackBossShootHit(
    std::shared_ptr<Entity> self, std::shared_ptr<Entity> other,
    std::vector<Network::Packet> &packets)
    {
        if (other == nullptr || self == nullptr)
            return;

        Network::data::DeathReason deathReason;

        if (other->getComponent<ECS::PlayerComponent>() != nullptr)
            deathReason = Network::data::DeathReason::ENEMY;
        else
            return;

        self->isEnabled = false;
        self->deathReason = deathReason;

        Network::data::DeadData deadData{self->getId(), deathReason};
        std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

        packets.push_back(*packet);
    }
}
