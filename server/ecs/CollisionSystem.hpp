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
            /**
             * @brief Construct a new CollisionSystem object
             */
            CollisionSystem();

            /**
             * @brief Destroy the CollisionSystem object
             */
            ~CollisionSystem() = default;

            /**
             * @brief Update the CollisionSystem: check for collisions between all entities
             * @param sceneManager
             * @param deltaTime
             * @param packetQueue
             */
            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;
    };
}

