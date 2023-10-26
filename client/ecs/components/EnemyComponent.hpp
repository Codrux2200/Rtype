/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#pragma once

#include <string>
#include <memory>
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Enemy component
     *
     */
    class EnemyComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new enemy Component object
             *
             * @param uid
             */
            EnemyComponent() = default;
            /**
             * @brief Destroy the enemy Component object
             *
             */
            ~EnemyComponent() = default;
            /**
             * @brief clone the component
             *
             * @return std::shared_ptr<IComponent>
             */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;
        protected:
        private:
            int _speed = 100;
    };
}
