/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerEntity
*/

#pragma once

#include "Entity.hpp"

namespace ECS {
    /**
     * @brief Player Entity
     */
    class PlayerEntity : public Entity {
        public:
            /**
             * @brief Construct a new Player Entity object
             *
             * @param id the id of the player
             */
            explicit PlayerEntity(int id);
            ~PlayerEntity() = default;
    };
}
