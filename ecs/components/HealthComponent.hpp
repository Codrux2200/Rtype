/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** healthComponent
*/

#pragma once

#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Health component
     *
     */
    class HealthComponent : public ECS::AComponent {
        public:
        /**
             * @brief Construct a new health Component object
             *
             * @param health
             */
            explicit HealthComponent(int health);

            std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief health of the entity
             */
            int health;
    };
}
