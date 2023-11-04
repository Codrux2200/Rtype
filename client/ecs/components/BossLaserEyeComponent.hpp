/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserEyeComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {

class BossLaserEyeComponent : public AGameComponent {
    public:
        BossLaserEyeComponent() = default;
        BossLaserEyeComponent(const BossLaserEyeComponent &other);

        [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

        void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

    private:
        float _timer = 0;
    };

} // namespace ECS
