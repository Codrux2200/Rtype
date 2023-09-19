/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "iSystem.hpp"

namespace ECS{
    class GameSystem : public ISystem{
        public:
            GameSystem();
            ~GameSystem();
             /**
             * @brief init Scene Manager
             * 
             * @param SceneManager 
             */
            void init(SceneManager &SceneManager);
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            void Update(SceneManager &SceneManager, int deltaTime);
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            void Destroy(SceneManager &SceneManager);
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */
