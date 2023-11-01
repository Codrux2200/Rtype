/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#pragma once

#include "Entity.hpp"
#include "HitboxComponent.hpp"

namespace ECS {
    class PlayerBullet : public Entity {
        public:
            explicit PlayerBullet(int id);
            ~PlayerBullet() = default;

        protected:
            void _callbackPlayerBulletHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
    };
}
