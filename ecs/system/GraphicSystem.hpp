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
             * @param SceneManager 
             */
            void init(SceneManager &SceneManager) override;
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            void update(SceneManager &SceneManager, int deltaTime) override;
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            void destroy(SceneManager &SceneManager) override;
        protected:
        private:
    };
};
#endif /* !GRAPHICSYSTEM_HPP_ */
