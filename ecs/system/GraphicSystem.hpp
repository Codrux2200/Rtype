/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "iSystem.hpp"

namespace ECS{
    class GraphicSystem : public ISystem{
        public:
            GraphicSystem();
            ~GraphicSystem();
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
};
#endif /* !GRAPHICSYSTEM_HPP_ */
