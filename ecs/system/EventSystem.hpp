/*
** EPITECH PROJECT, 2023
** Rtype
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
             * @param sceneManager 
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

#endif /* !PARTICLESYSTEM_HPP_ */
