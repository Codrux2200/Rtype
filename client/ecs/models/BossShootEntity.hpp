/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootEntity
*/

#pragma once

#include "Entity.hpp"

class BossShootEntity : public ECS::Entity {
    public:
        BossShootEntity(int id);
        ~BossShootEntity() = default;
};
