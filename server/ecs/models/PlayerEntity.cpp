/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "PlayerEntity.hpp"
#include "BossComponent.hpp"
#include "BossShootComponent.hpp"
#include "DeadData.hpp"
#include "EnemyComponent.hpp"
#include "HitboxComponent.hpp"
#include "PacketManager.hpp"
#include "PlayerBulletComponent.hpp"
#include "PlayerComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"
#include "EnemyBulletComponent.hpp"

PlayerEntity::PlayerEntity() : Entity(0)
{
    addComponent(std::make_shared<ECS::PlayerComponent>());
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    addComponent(std::make_shared<ECS::VelocityComponent>(0, 0));
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&PlayerEntity::_callbackPlayerHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{0, 0}, {60, 40}}));
    isEnabled = false;
    updateGameComponents();
}

void PlayerEntity::_callbackPlayerHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    if (other == nullptr || self == nullptr)
        return;

    Network::data::DeathReason reason;

    if (other->getComponent<ECS::EnemyComponent>() != nullptr ||
        other->getComponent<ECS::BossShootComponent>() != nullptr ||
        other->getComponent<ECS::EnemyBulletComponent>() != nullptr
    )
        reason = Network::data::DeathReason::ENEMY;
    else
        return;

    Network::data::DeadData deadData{self->getId(), reason};
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

    packets.push_back(*packet);
    self->isEnabled = false;
    std::cout << "Player " << self->getId() << " is dead" << std::endl;
}
