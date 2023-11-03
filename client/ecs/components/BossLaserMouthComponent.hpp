/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserMouthComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {

    class BossLaserMouthComponent : public AGameComponent {
        public:
            BossLaserMouthComponent() = default;
            BossLaserMouthComponent(const BossLaserMouthComponent& other);

            std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

        private:
            float _timer = 0;
    };

} // namespace ECS

