/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_
#include "../SceneManager.hpp"

namespace ECS
{
    /**
     * @brief System Type
     * 
     */
    enum SystemType {
        GAME = 0,
        GRAPHIC = 1,
        EVENT = 2,
        PARTICLE = 3,
        COLLIDE = 4,
        AUDIO = 5,
        NETWORK = 6,
    };
    /**
     * @brief ISystem class
     * 
     */
    class ISystem {
        public :
            /**
             * @brief init Scene Manager
             * 
             * @param sceneManager 
             */
            virtual void init(SceneManager &sceneManager) = 0;
            /**
             * @brief update all the system
             * 
             * @param sceneManager 
             * @param deltaTime 
             */
            virtual void update(SceneManager &sceneManager, SceneType SceneType, int deltaTime) = 0;
    };
} // namespace ECS


#endif /* !ISystem_HPP_ */
