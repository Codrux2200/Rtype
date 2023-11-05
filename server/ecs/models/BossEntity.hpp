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
        /**
         * @brief Construct a new Boss Entity object
         *
         * @param shootFunction the shoot function
         * @param id the id of the entity
         */
        explicit BossEntity(const ECS::bossShootFunction& shootFunction, int id);
        ~BossEntity() = default;

    private:
        /**
         * @brief the boss hit callback
         */
        void _callbackBossHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
        /**
         * @brief the boss laser hit callback
         */
        void _callbackBossLaserHit(std::shared_ptr<Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
