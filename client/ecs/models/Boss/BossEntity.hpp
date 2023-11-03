/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossEntity
*/

#pragma once

#include "Entity.hpp"
#include "Packet.hpp"
#include "BossComponent.hpp"

class BossEntity : public ECS::Entity {
    public:
        explicit BossEntity(const bossLaserGenerator& laserGenerator, int id = 0);
        ~BossEntity() = default;
};
