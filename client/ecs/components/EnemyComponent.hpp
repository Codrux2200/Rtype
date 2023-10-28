/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#pragma once

#include <string>
#include <memory>
#include "AGameComponent.hpp"

namespace ECS {
    /**
     * @brief Enemy component
     *
     */
    class EnemyComponent : public AGameComponent {
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

            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            bool onDestroy(Entity &entity, Network::data::DeathReason reason) override;

        private:
            int _speed = 100;
            bool _soundPlayed = false;
    };
}
