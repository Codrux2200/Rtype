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
            explicit EnemyComponent(EnemyShootFunction shootFunction, ECS::Entity::EntityType);
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

            [[nodiscard]] ECS::Entity::EntityType getEnemyType() const { return _type; }

        private:

            /**
             * @brief The default x axis speed of the enemy
             */
            float _xspeed = 0;
            /**
             * @brief The default y axis speed of the enemy
             */
            float _yspeed = 0;
            /**
             * @brief randomize the shoot rate of the enemy
            */
            float _random = 0;
            float _timer = 0;

            /**
             * @brief The rate of the enemy shoot
             */
            float _rate = 10;
            ECS::Entity::EntityType _type;
            EnemyShootFunction _shootFunction;
    };
}