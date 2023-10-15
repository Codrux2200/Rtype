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
            GameSystem();
            /**
             * @brief Destroy the Game System object
             *
             */
            ~GameSystem();
            /**
             * @brief update the game system
             *
             * @param sceneManager
             * @param SceneType
             * @param deltaTime
             */
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */
