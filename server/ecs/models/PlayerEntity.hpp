/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerEntity
*/

#pragma once

#include "Entity.hpp"

class PlayerEntity : public ECS::Entity {
    public:
        PlayerEntity();
        ~PlayerEntity() = default;

        void init();
        void update();
};

