/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class PlayerBulletComponent : public AGameComponent {
        public:
            PlayerBulletComponent() = default;
            ~PlayerBulletComponent() = default;

            /**
             * @brief Clone the component
             *
             */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief update the boss laser eye
             *
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
            */
            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;

            /**
             * @brief the damage
             *
            */
            int damage = 1;
    };
}
