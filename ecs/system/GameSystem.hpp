/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "ISystem.hpp"

namespace ECS {
    /**
     * @brief Game System
     *
     */
    class GameSystem : public ISystem {
        public:
            /**
             * @brief Construct a new Game System object
             *
             */
            GameSystem() = default;

            /**
             * @brief update the game system
             *
             * @param sceneManager
             * @param SceneType
             * @param deltaTime
             */
            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */
