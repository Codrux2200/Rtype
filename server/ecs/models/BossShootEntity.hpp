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
            BossShootEntity(int id, float vx, float vy);
            ~BossShootEntity() = default;

            void _callbackBossShootHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
        private:
    };
}
