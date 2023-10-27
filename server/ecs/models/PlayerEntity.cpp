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
#include "PlayerComponent.hpp"
#include "PlayerBulletComponent.hpp"

PlayerEntity::PlayerEntity() : Entity(0)
{
    addComponent(std::make_shared<ECS::PlayerComponent>());
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    addComponent(std::make_shared<ECS::HitboxComponent>(std::bind(&PlayerEntity::_callbackPlayerHit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    std::vector<std::pair<int, int>>{{0, 0}, {60, 40}}));
    isEnabled = false;
}

void PlayerEntity::_callbackPlayerHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets)
{
    if (other->getId() < 4 || other->getComponent<ECS::PlayerBulletComponent>())
        return;

    Network::data::DeadData deadData{self->getId()};
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::DEAD, &deadData);

    packets.push_back(*packet);
    self->isEnabled = false;
    std::cout << "Player " << this->getId() << " is dead" << std::endl;
}
