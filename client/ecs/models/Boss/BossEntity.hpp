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

/**
 * @brief Boss Entity
 */
class BossEntity : public ECS::Entity {
    public:
        /**
         * @brief Construct a new Boss Entity object
         *
         * @param laserGenerator the laser generator
         * @param id the id
         */
        explicit BossEntity(const bossLaserGenerator& laserGenerator, int id = 0);
        ~BossEntity() = default;
};
