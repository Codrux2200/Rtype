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

void ECS::PlayerComponent::execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
{
    auto positionComponent = entity.getComponent<ECS::PositionComponent>();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        positionComponent->move(0, -_speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        positionComponent->move(0, _speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        positionComponent->move(-_speed * dt, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        positionComponent->move(_speed * dt, 0);
    }
}

std::vector<int> ECS::PlayerComponent::getValue() const
{
    return std::vector<int>();
}

void ECS::PlayerComponent::setValue(std::vector<int> values)
{

}
