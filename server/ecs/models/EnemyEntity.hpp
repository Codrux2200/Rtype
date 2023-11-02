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

using EnemyShootFunction = std::function<void()>;
class EnemyEntity : public ECS::Entity {
    public:
        explicit EnemyEntity(EnemyShootFunction shootFunction, int id);

        ~EnemyEntity() = default;

    private:
        void _callbackEnemyHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
