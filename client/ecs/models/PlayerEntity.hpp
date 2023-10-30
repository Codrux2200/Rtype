/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerEntity
*/

#pragma once

#include "Entity.hpp"

namespace ECS {
    class PlayerEntity : public Entity {
        public:
            explicit PlayerEntity(int id);
            ~PlayerEntity() = default;
    };
}
