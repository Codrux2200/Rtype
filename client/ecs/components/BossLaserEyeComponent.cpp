/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserEyeComponent
*/

#include "BossLaserEyeComponent.hpp"

namespace ECS {

        void BossLaserEyeComponent::update(std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt)
        {
            _timer += dt;
            if (_timer > 1.1f) {
                entity.deathReason = Network::data::DeathReason::TIMEOUT;
            }
        }

        std::shared_ptr<IComponent> BossLaserEyeComponent::clone() const
        {
            return std::make_shared<BossLaserEyeComponent>(*this);
        }

        BossLaserEyeComponent::BossLaserEyeComponent(const BossLaserEyeComponent &other)
        {
            _timer = other._timer;
        }
} // namespace ECS
