/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** ISystem
*/

#ifndef ISystem_HPP_
#define ISystem_HPP_
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


#endif /* !ISystem_HPP_ */
