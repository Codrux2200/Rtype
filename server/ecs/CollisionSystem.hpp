/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem
*/

#pragma once

#include "ISystem.hpp"

namespace ECS {
    class CollisionSystem : public ISystem {
        public:
            CollisionSystem();

            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;
    };
}

