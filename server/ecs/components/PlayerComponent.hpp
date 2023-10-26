/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#pragma once

#include "AComponent.hpp"

namespace ECS {
    class PlayerComponent : public AComponent {
        public:
            PlayerComponent() = default;
            ~PlayerComponent() = default;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;
    };

} // namespace ECS

