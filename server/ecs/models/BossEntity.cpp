/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossEntity
*/

#include "BossEntity.hpp"
#include "PositionComponent.hpp"
#include "HitboxComponent.hpp"
#include "BossComponent.hpp"

BossEntity::BossEntity(const ECS::bossShootFunction& shootFunction, int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&BossEntity::_callbackBossHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{0, 0}, {360, 360}}));

    // Boss laser hitbox up
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&BossEntity::_callbackBossLaserHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{-500, 0}, {360, 180}}))
        ->isEnabled = false;

    // Boss laser hitbox down
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&BossEntity::_callbackBossLaserHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{-500, 180}, {360, 360}}))
        ->isEnabled = false;

    addComponent(std::make_shared<ECS::PositionComponent>(1160, 120));
    addComponent(std::make_shared<ECS::BossComponent>(shootFunction));
    updateGameComponents();
}

void BossEntity::_callbackBossHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
//    auto &position = self->getComponent<ECS::PositionComponent>();
//    auto &hitbox = self->getComponent<ECS::HitboxComponent>();
//
//    if (other->getComponent<ECS::HitboxComponent>().isColliding(hitbox)) {
//        packets.emplace_back(Network::PacketType::DESTROY_ENTITY, self->getId());
//        packets.emplace_back(Network::PacketType::DESTROY_ENTITY, other->getId());
//    }
}

void BossEntity::_callbackBossLaserHit(std::shared_ptr<Entity> self,
std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    // Do nothing, just here to fill the hitbox callback
}
