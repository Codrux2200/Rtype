/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyBulletComponent
*/

#pragma once

#include "Entity.hpp"
#include "HitboxComponent.hpp"

namespace ECS {
    class EnemyBullet : public Entity {
        public:
            EnemyBullet(int id);
            ~EnemyBullet() = default;

        protected:
            void _callbackEnemyBulletHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
    };
}
