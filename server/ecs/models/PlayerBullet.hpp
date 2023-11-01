/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#pragma once

#include "Entity.hpp"
#include "HitboxComponent.hpp"

namespace ECS {
    class PlayerBullet : public Entity {
        public:
            /**
             * @brief Construct a new PlayerBullet object with the given id
             * @param id
             */
            explicit PlayerBullet(int id);
            /**
             * @brief Destroy the PlayerBullet object
             */
            ~PlayerBullet() = default;

        protected:
            /**
             * @brief Callback called when the player bullet collides with another entity
             * @param self
             * @param other
             * @param packets
             */
            void _callbackPlayerBulletHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
    };
}
