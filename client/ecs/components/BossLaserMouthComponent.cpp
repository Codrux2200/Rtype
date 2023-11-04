/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserMouthComponent
*/

#include "BossLaserMouthComponent.hpp"

namespace ECS {

    BossLaserMouthComponent::BossLaserMouthComponent(const BossLaserMouthComponent &other)
    {
        _timer = other._timer;
    }

    std::shared_ptr<IComponent> BossLaserMouthComponent::clone() const
    {
        return std::make_shared<BossLaserMouthComponent>(*this);
    }

    void BossLaserMouthComponent::update(std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt)
    {
        _timer += dt;
        if (_timer > 1.1f) {
            entity.deathReason = Network::data::TIMEOUT;
        }
    }

} // namespace ECS