/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_
#include <string>
#include "ISystem.hpp"

namespace ECS{
    /**
     * @brief Abstact system implementation
     * 
     */
    class ASystem : public ISystem {
        public:
            /**
             * @brief init and update the scene
             * 
             * @param sceneManager 
             * @param SceneType 
             * @param deltaTime 
             */
            void update(SceneManager &sceneManager, SceneType SceneType, int deltaTime) override;
            /**
             * @brief Type object
             * 
             */
            SystemType typeSystem;
        protected:
        private:
    };
}

#endif /* !ASYSTEM_HPP_ */
