/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** iSystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_
#include "../SceneManager.hpp"

namespace ECS
{
    enum SystemType {
        GAME = 0,
        GRAPHIQUE = 1,
        EVENT = 2,
        PARTICLE = 3,
        COLLIDE = 4,
        AUDIO = 5,
        NETWORK = 6,
    };

    class ISystem {
        public :
            /**
             * @brief init Scene Manager
             * 
             * @param SceneManager 
             */
            virtual void init(SceneManager &SceneManager) = 0;
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            virtual void Update(SceneManager &SceneManager, int deltaTime) = 0;
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            virtual void Destroy(SceneManager &SceneManager) = 0;
    };
} // namespace ECS


#endif /* !ISYSTEM_HPP_ */
