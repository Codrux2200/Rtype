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
    class EnemyEntity : public ECS::Entity {
        public:
            EnemyEntity(int id);
            ~EnemyEntity();
    };
}
