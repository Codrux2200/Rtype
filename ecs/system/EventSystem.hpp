/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** EventSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "ISystem.hpp"

namespace ECS {
    /**
     * @brief Event System
     * 
     */
    class EventSystem : public ISystem{
        public:
            /**
             * @brief Construct a new Event System object
             * 
             */
            EventSystem();
            /**
             * @brief Destroy the Event System object
             * 
             */
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
