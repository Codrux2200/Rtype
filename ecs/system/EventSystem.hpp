/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** EventSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "iSystem.hpp"

namespace ECS{
    class EventSystem : public ISystem{
        public:
            EventSystem();
            ~EventSystem();
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

#endif /* !PARTICLESYSTEM_HPP_ */
