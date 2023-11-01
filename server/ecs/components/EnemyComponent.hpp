/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class EnemyComponent : public ECS::AGameComponent {
        public:
            /**
             * @brief Construct a new EnemyComponent object
             */
            EnemyComponent();
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
    };
}