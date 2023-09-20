/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
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
            void init(SceneManager &SceneManager) override;
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            void Update(SceneManager &SceneManager, int deltaTime) override;
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            void Destroy(SceneManager &SceneManager) override;
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */
