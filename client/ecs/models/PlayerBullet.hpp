/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBullet
*/

#pragma once

#include "Entity.hpp"

namespace ECS {
    /**
     * @brief PlayerBullet component
     */
    class PlayerBullet : public Entity {
        public:
            /**
             * @brief Construct a new PlayerBullet object
             *
             * @param id the id of the player bullet
             */
            PlayerBullet(int id);
            ~PlayerBullet() = default;
    };
}
