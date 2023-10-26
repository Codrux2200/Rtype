/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBullet
*/

#include "PlayerBullet.hpp"
#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"
#include "HitboxComponent.hpp"
#include "EnemyComponent.hpp"
#include "DeadData.hpp"
#include "PacketManager.hpp"

ECS::PlayerBullet::PlayerBullet(int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    addComponent(std::make_shared<ECS::PlayerBulletComponent>());
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&ECS::PlayerBullet::_callbackPlayerBulletHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{0, 0}, {80, 60}}));
}

void ECS::PlayerBullet::_callbackPlayerBulletHit(
std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    // Cancel player contacts
    if (other->getId() < 4)
        return;

    auto enemyComponent = other->getComponent<ECS::EnemyComponent>();

    if (enemyComponent == nullptr)
        return;

    // TODO: Check if it has a healthComponent to decrease its health before killing it

    // Destroy the enemy //
    other->toDestroy = true;
    other->isEnabled = false;

    Network::data::DeadData deadData{other->getId()};
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

    packets.push_back(*packet);

    // Destroy the bullet //
    self->isEnabled = false;
    self->toDestroy = true;

    deadData.id = self->getId();

    packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);
    packets.push_back(*packet);
}
