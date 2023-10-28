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
            PlayerBullet(int id);
            ~PlayerBullet() = default;
    };
}
