/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AGameComponent
*/

#pragma once

#include "AComponent.hpp"
#include "Packet.hpp"
#include "Entity.hpp"

namespace ECS {

    class AGameComponent : public AComponent {
        public:
            virtual void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) = 0;
            virtual SceneType getSceneChange();
    };
}