/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "ISystem.hpp"

namespace ECS {
    /**
     * @brief Graphic System
     * 
     */
    class GraphicSystem : public ISystem{
        public:
            /**
             * @brief Construct a new Graphic System object
             * 
             */
            GraphicSystem();
            /**
             * @brief Destroy the Graphic System object
             * 
             */
            ~GraphicSystem();
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
};
#endif /* !GRAPHICSYSTEM_HPP_ */
