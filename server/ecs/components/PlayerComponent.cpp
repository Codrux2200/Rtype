/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerComponent
*/

#include <iostream>
#include "PlayerComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerComponent::clone() const
    {
        return std::make_shared<PlayerComponent>();
    }

    void PlayerComponent::update(
    std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt)
    {
        _lastFire++;
    }

    int PlayerComponent::getLastFire() const
    {
        std::cout << "last fire: " << _lastFire << std::endl;
        return _lastFire;
    }

    void PlayerComponent::resetLastFire()
    {
        _lastFire = 0;
    }

} // namespace ECS
