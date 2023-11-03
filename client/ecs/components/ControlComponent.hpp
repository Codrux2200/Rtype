/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ControlComponent
*/

#pragma once

#include <memory>
#include <string>
#include "AEventComponent.hpp"

namespace ECS {
    class ControlComponent : public AEventComponent {
        public:
            ControlComponent();

            [[nodiscard]] std::vector<int> getValue() const final;

            void setValue(std::vector<int> values) final;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            bool execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) final;

    };
}
