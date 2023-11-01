/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class PlayerComponent : public AGameComponent {
        public:
            PlayerComponent() = default;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            int fireRate = 5;

            [[nodiscard]] int getLastFire() const;

            void resetLastFire();

        private:
            int _lastFire = 5;
    };

} // namespace ECS

