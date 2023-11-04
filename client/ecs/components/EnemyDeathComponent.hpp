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
     * @brief Enemy death component
     *
     * Provides a behavior on enemy death, such as playing a sound
     */
    class EnemyDeathComponent : public AGameComponent {
        public:
            /**
             * @brief Construct a new enemy death Component object
             *
             * @param uid
             */
            EnemyDeathComponent() = default;
            /**
             * @brief Destroy the enemy DeathComponent object
             *
             */
            ~EnemyDeathComponent() = default;
            /**
             * @brief clone the component
             *
             * @return std::shared_ptr<IComponent>
             */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;

            bool onDestroy(Entity &entity, Network::data::DeathReason reason, float dt) override;

        private:
            int _speed = 100;
            bool _soundPlayed = false;
    };
}
