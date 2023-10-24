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

void ECS::ControlComponent::execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
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

std::vector<int> ECS::ControlComponent::getValue() const
{
    return std::vector<int>();
}

void ECS::ControlComponent::setValue(std::vector<int> values)
{

}
