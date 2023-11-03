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
    class EnemyEntity : public Entity {
        public:
            EnemyEntity(int id, ECS::Entity::EntityType type);
            ~EnemyEntity() = default;
    };
}
