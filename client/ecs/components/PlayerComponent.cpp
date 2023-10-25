/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"
#include <iostream>
#include "PositionComponent.hpp"
#include "ShootComponent.hpp"

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
    auto shootComponent = entity.getComponent<ECS::ShootComponent>();

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shootComponent->newShot(positionComponent->getValue());
    }
}

std::vector<int> ECS::PlayerComponent::getValue() const
{
    return std::vector<int>();
}

void ECS::PlayerComponent::setValue(std::vector<int> values)
{

}
