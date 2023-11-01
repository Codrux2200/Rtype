/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** velocityComponent
*/

#pragma once

#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Velocity component
     *
     */
    class VelocityComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new velocity Component object
             *
             */
            VelocityComponent() = default;
            VelocityComponent(float vx, float vy);

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            float vx = 0;
            float vy = 0;
    };
}
