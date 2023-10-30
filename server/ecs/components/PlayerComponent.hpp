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
            /**
             * @brief Construct a new PlayerComponent object
             */
            PlayerComponent() = default;

            /**
             * @brief Clone the PlayerComponent object
             * @return std::shared_ptr<IComponent> The newly cloned PlayerComponent
             */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;
    };

} // namespace ECS

