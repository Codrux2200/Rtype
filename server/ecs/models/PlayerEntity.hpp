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
        PlayerEntity();
        ~PlayerEntity() = default;

    private:
        void _callbackPlayerHit(std::shared_ptr<ECS::Entity> other, std::vector<Network::Packet> &packets);
};
