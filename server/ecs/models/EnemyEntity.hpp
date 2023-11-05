/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyEntity
*/

#pragma once

#include <functional>
#include "Entity.hpp"
#include "Packet.hpp"

using EnemyShootFunction = std::function<void(int, int)>;
class EnemyEntity : public ECS::Entity {
    public:
        /**
         * @brief Construct a new EnemyEntity object with the given id
         * @param id
         */
        explicit EnemyEntity(EnemyShootFunction shootFunction, int id, ECS::Entity::EntityType type);

        /**
         * @brief Destroy the EnemyEntity object
         */
        ~EnemyEntity() = default;

    private:
        void _callbackEnemyHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
