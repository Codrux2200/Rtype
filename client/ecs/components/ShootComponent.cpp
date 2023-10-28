/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ShootComponent
*/

#include "ShootComponent.hpp"
#include "PacketManager.hpp"

void ECS::ShootComponent::execute(
std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::cout << "shoot" << std::endl;
        std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::SHOOT);
        packetsQueue.push_back(*packet);
    }
}

std::shared_ptr<ECS::IComponent> ECS::ShootComponent::clone() const
{
    return std::make_shared<ECS::ShootComponent>();
}
