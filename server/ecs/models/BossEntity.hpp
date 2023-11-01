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

class BossEntity : public ECS::Entity {
    public:
        explicit BossEntity(const ECS::bossShootFunction& shootFunction, int id);
        ~BossEntity() = default;

    private:
        void _callbackBossHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
        void _callbackBossLaserHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
