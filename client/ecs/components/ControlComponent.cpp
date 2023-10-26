/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ControlComponent
*/

#include <iostream>
#include "ControlComponent.hpp"
#include "PositionComponent.hpp"

ECS::ControlComponent::ControlComponent(ECS::eventCallback callback) : EventComponent(callback)
{
}

std::shared_ptr<ECS::IComponent> ECS::ControlComponent::clone() const
{
    return std::make_shared<ECS::ControlComponent>(_callback);
}

void ECS::ControlComponent::execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
{
    std::unique_ptr<Network::Packet> packet;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        packet = Network::PacketManager::createPacket(Network::PacketType::MOVE_UP);
        packetsQueue.push_back(*packet);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        packet = Network::PacketManager::createPacket(Network::PacketType::MOVE_DOWN);
        packetsQueue.push_back(*packet);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        packet = Network::PacketManager::createPacket(Network::PacketType::MOVE_LEFT);
        packetsQueue.push_back(*packet);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        packet = Network::PacketManager::createPacket(Network::PacketType::MOVE_RIGHT);
        packetsQueue.push_back(*packet);
    }
}

std::vector<int> ECS::ControlComponent::getValue() const
{
    return std::vector<int>();
}

void ECS::ControlComponent::setValue(std::vector<int> values)
{

}
