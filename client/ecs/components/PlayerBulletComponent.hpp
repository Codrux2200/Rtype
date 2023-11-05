/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    /**
     * @brief Player Bullet Component
     */
    class PlayerBulletComponent : public AGameComponent {
        public:
            PlayerBulletComponent() = default;
            ~PlayerBulletComponent() = default;

            /**
             * @brief Clone the component
            */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief update the player bullet
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
            /**
             * @brief Action to do when the player bullet is destroyed
             * 
            */
            bool onDestroy(Entity &entity, Network::data::DeathReason reason, float dt) override;

        private:
            /**
             * @brief hit initialize
            */
            bool Hitinitialize = false;
    };
}
