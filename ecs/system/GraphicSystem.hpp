/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "ASystem.hpp"
#include <SFML/Graphics.hpp>

namespace ECS {
    /**
     * @brief Graphic System
     * 
     */
    class GraphicSystem : public ASystem{
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
             * @brief update the Graphic System
             * 
             * @param sceneManager 
             * @param SceneType 
             * @param deltaTime 
             */
            void update(SceneManager &sceneManager, SceneType SceneType, int deltaTime) override;
            /**
             * @brief Get the Window object
             * 
             * @return sf::RenderWindow 
             */
            sf::RenderWindow &getWindow();
        protected:
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Vector2u _modeSize;
        private:
    };
};
#endif /* !GRAPHICSYSTEM_HPP_ */
