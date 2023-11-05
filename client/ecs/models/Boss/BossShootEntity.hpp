/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootEntity
*/

#pragma once

#include "Entity.hpp"

/**
 * @brief BossShoot Entity
 */
class BossShootEntity : public ECS::Entity {
    public:
        /**
         * @brief Construct a new Boss Shoot Entity object
         *
         * @param id the id
         */
        explicit BossShootEntity(int id);
        ~BossShootEntity() = default;
};
