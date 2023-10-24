/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#include <iostream>
#include "PlayerComponent.hpp"
#include "PositionComponent.hpp"

ECS::PlayerComponent::PlayerComponent(ECS::eventCallback callback) : EventComponent(callback)
{
}

std::shared_ptr<ECS::IComponent> ECS::PlayerComponent::clone() const
{
    return std::make_shared<ECS::PlayerComponent>(_callback);
}

void ECS::PlayerComponent::execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
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

std::vector<int> ECS::PlayerComponent::getValue() const
{
    return std::vector<int>();
}

void ECS::PlayerComponent::setValue(std::vector<int> values)
{

}
