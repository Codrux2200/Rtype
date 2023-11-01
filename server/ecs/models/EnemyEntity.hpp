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
        explicit EnemyEntity(int id);
        ~EnemyEntity() = default;

    private:
        void _callbackEnemyHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
}
