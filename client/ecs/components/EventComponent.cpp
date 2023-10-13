/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EventComponent
*/

#include <iostream>
#include "EventComponent.hpp"

ECS::EventComponent::EventComponent(eventCallback callback) : _callback(callback)
{
}

std::shared_ptr<ECS::IComponent> ECS::EventComponent::clone() const
{
    return std::make_shared<ECS::EventComponent>(_callback);
}

void ECS::EventComponent::execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue)
{
    std::cout << "EventComponent execute" << std::endl;
    _callback(packetManager, packetsQueue);
}
