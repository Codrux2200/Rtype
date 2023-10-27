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
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&PlayerEntity::_callbackPlayerHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{0, 0}, {80, 60}}));
    isEnabled = false;
}

void PlayerEntity::_callbackPlayerHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    // if it is a player, don't care about collision

    std::cout << "Player hit with " << other->getId() << std::endl;
    if (other->getId() < 4) {
        std::cout << "Cancelled" << std::endl;
        return;
    }
    Network::data::DeadData deadData{self->getId()};
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

    packets.push_back(*packet);
    self->isEnabled = false;
    std::cout << "Player " << this->getId() << " is dead" << std::endl;
}
