/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerEntity
*/

#pragma once

#include "Entity.hpp"
#include "Packet.hpp"

class PlayerEntity : public ECS::Entity {
    public:
        /**
         * @brief Construct a new PlayerEntity object
         */
        PlayerEntity();

        /**
         * @brief Destroy the PlayerEntity object
         */
        ~PlayerEntity() = default;

    private:
        /**
         * @brief Callback called when the player collides with another entity
         * @param self
         * @param other
         * @param packets
         */
        void _callbackPlayerHit(std::shared_ptr<ECS::Entity> self, std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
