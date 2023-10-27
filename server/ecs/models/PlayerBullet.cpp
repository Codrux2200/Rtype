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
    if (other == nullptr || self == nullptr)
        return;
    
    // Cancel player contacts
    if (other->getId() < 4 || other->getComponent<ECS::PlayerBulletComponent>() != nullptr)
        return;

    self->isEnabled = false;
    self->toDestroy = true;

    Network::data::DeadData deadData{self->getId()};
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

    packets.push_back(*packet);
}
