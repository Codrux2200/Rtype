/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyEntity
*/

#include "EnemyEntity.hpp"
#include "EnemyComponent.hpp"
#include "HitboxComponent.hpp"
#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"
#include "PacketManager.hpp"
#include "EnemyBulletComponent.hpp"

EnemyEntity::EnemyEntity(EnemyShootFunction shootFunction, int id, ECS::Entity::EntityType type) : Entity(id)
{
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&EnemyEntity::_callbackEnemyHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{5, 5}, {75, 75}}));
    addComponent(std::make_shared<ECS::PositionComponent>(700, 200));
    addComponent(std::make_shared<ECS::EnemyComponent>(shootFunction, type));
    updateGameComponents();
}

void EnemyEntity::_callbackEnemyHit(std::shared_ptr<ECS::Entity> self,
std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    if (other == nullptr || self == nullptr)
        return;
    if (other->getComponent<ECS::PlayerBulletComponent>() != nullptr) {
        self->isEnabled = false;
        self->deathReason = Network::data::DeathReason::PLAYER_BULLET;
        Network::data::DeadData deadData {self->getId(), Network::data::DeathReason::PLAYER_BULLET};
        std::shared_ptr<Network::Packet> deadPacket = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);
        packets.push_back(*deadPacket);
    }
}
