/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyEntity
*/

#pragma once

#include "Entity.hpp"
#include "Packet.hpp"

namespace ECS {
    /**
     * @brief Enemy Entity
     */
    class EnemyEntity : public Entity {
        public:
            /**
             * @brief Construct a new Enemy Entity object
             *
             * @param id the id of the enemy
             * @param type the entity type corresponding
             * to the enemy type
             */
            EnemyEntity(int id, ECS::Entity::EntityType type);
            ~EnemyEntity() = default;
    };
}
