/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerComponent
*/


#include "PlayerComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerComponent::clone() const
    {
        return std::make_shared<PlayerComponent>();
    }

    void PlayerComponent::update(
    std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt)
    {
        lastFire++;
    }

} // namespace ECS