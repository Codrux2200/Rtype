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
        explicit BossEntity(int id);
        ~BossEntity() = default;
};
