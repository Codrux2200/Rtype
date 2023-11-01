/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class BossShootComponent : public AGameComponent {
        public:
            BossShootComponent() = default;
            ~BossShootComponent() = default;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;
    };
}

