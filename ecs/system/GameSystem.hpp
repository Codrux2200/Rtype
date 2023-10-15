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
    class GameSystem : public ISystem{
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
             * @brief init Scene Manager
             * 
             * @param SceneManager 
             */
            void init(SceneManager &sceneManager) override;
            /**
             * @brief update all the system
             * 
             * @param sceneManager 
             * @param deltaTime 
             */
            void update(SceneManager &sceneManager, int deltaTime) override;
            /**
             * @brief destroy all the system
             * 
             * @param sceneManager 
             */
            void destroy(SceneManager &sceneManager) override;
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */
