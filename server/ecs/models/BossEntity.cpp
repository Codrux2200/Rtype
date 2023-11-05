/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossEntity
*/

#include "BossEntity.hpp"
#include "BossComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxComponent.hpp"
#include "PacketManager.hpp"
#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"

BossEntity::BossEntity(const ECS::bossShootFunction& shootFunction, int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(1100, 0));
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&BossEntity::_callbackBossHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{100, 0}, {360, 310}}));

    // Boss laser hitbox up
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&BossEntity::_callbackBossLaserHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{-500, 87}, {360, 151}}))
        ->isEnabled = false;

    // Boss laser hitbox down
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&BossEntity::_callbackBossLaserHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{-500, 190}, {360, 281}}))
        ->isEnabled = false;

    addComponent(std::make_shared<ECS::PositionComponent>(1160, 120));
    addComponent(std::make_shared<ECS::BossComponent>(shootFunction));
    addComponent(std::make_shared<ECS::HealthComponent>(3));
    updateGameComponents();
}

void BossEntity::_callbackBossHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    if (other == nullptr || self == nullptr)
        return;
    if (other->getComponent<ECS::PlayerBulletComponent>() != nullptr) {
        auto healthComponent = self->getComponent<ECS::HealthComponent>();

        if (healthComponent == nullptr)
            return;

        healthComponent->health -= 1;

        // TODO: Send health update packet

        if (healthComponent->health <= 0) {
            self->isEnabled = false;
            self->deathReason = Network::data::DeathReason::PLAYER_BULLET;

            Network::data::DeadData deadData {self->getId(), Network::data::DeathReason::PLAYER_BULLET};
            std::shared_ptr<Network::Packet> deadPacket = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

            packets.push_back(*deadPacket);
        }
    }
}

void BossEntity::_callbackBossLaserHit(std::shared_ptr<Entity> self,
std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    // Do nothing, just here to fill the hitbox callback
}
