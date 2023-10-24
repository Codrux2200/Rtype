/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "PositionComponent.hpp"
#include "EnemyComponent.hpp"

ECS::EnemyComponent::EnemyComponent(eventCallback callback) : EventComponent(callback)
{
}

std::shared_ptr<ECS::IComponent> ECS::EnemyComponent::clone() const
{
    return std::make_shared<ECS::EnemyComponent>(_callback);
}

void ECS::EnemyComponent::execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
{
    auto positionComponent = entity.getComponent<ECS::PositionComponent>();

    positionComponent->move(-_speed * dt, 0);
}
