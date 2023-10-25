/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "PlayerEntity.hpp"
#include "PositionComponent.hpp"
#include "HitboxComponent.hpp"
#include "DeadData.hpp"
#include "PacketManager.hpp"

PlayerEntity::PlayerEntity() : Entity(0)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&PlayerEntity::_callbackPlayerHit, this, std::placeholders::_1, std::placeholders::_2),
    std::vector<std::pair<int, int>>{{0, 0}, {80, 60}}));
}

void PlayerEntity::_callbackPlayerHit(std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    if (other->getId() < 4)
        return;
    Network::data::DeadData deadData{this->getId()};
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

    packets.push_back(*packet);
    this->isEnabled = false;
}