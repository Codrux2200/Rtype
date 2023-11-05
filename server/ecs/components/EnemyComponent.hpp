/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/

#pragma once

#include <functional>
#include "AGameComponent.hpp"

namespace ECS {
    using EnemyShootFunction = std::function<void(int, int)>;
    class EnemyComponent : public ECS::AGameComponent {
        public:
            /**
             * @brief Construct a new EnemyComponent object
             */
            explicit EnemyComponent(EnemyShootFunction shootFunction);
            /**
             * @brief Destroy the EnemyComponent object
             */
            ~EnemyComponent() = default;

            /**
             * @brief Clone the EnemyComponent object
             * @return std::shared_ptr<IComponent> The newly cloned EnemyComponent
             */
            [[nodiscard]] std::shared_ptr<ECS::IComponent>
            clone() const override;

            /**
             * @brief Update the EnemyComponent: move the enemy, make it shoot, update its life etc.
             * @param packets
             * @param entity
             * @param deltaTime
             */
            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;
        private:

            /**
             * @brief The default speed of the enemy
             */
            float _speed = 100;
            /**
             * @brief randomize the shoot rate of the enemy
            */
            float random = std::rand() % 3;
            float timer = 0;

            /**
             * @brief The rate of the enemy shoot
             */
            float rate = 1 + random;
            EnemyShootFunction _shootFunction;
    };
}
