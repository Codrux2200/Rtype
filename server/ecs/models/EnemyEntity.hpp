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
        /**
         * @brief Construct a new EnemyEntity object with the given id
         * @param id
         */
        explicit EnemyEntity(int id);

        /**
         * @brief Destroy the EnemyEntity object
         */
        ~EnemyEntity() = default;

    private:
        void _callbackEnemyHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
}
