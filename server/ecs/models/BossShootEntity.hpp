/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootEntity
*/

#pragma once

#include "Entity.hpp"
#include "Packet.hpp"

namespace ECS {
    class BossShootEntity : public Entity {
        public:
            /**
             * @brief Construct a new Boss Shoot Entity object
             *
             * @param id the id of the entity
             * @param vx the x velocity
             * @param vy the y velocity
             */
            explicit BossShootEntity(int id, float vx = 0, float vy = 0);
            ~BossShootEntity() = default;

        private:
            /**
             * @brief the boss shoot hit callback
             */
            void _callbackBossShootHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
    };
}
