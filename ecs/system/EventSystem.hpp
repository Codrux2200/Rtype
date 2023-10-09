/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EventSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "ASystem.hpp"
#include <SFML/Graphics.hpp>

namespace ECS {
    /**
     * @brief Event System
     * 
     */
    enum SFMLKeys {
        up = sf::Keyboard::Up,
        down = sf::Keyboard::Down,
        left = sf::Keyboard::Left,
        right = sf::Keyboard::Right,
        space = sf::Keyboard::Space,
        w = sf::Keyboard::W,
        a = sf::Keyboard::A,
        z = sf::Keyboard::Z,
        q = sf::Keyboard::Q,
        s = sf::Keyboard::S,
        d = sf::Keyboard::D,
    };
    class EventSystem : public ASystem{
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
             * @brief update the event system
             * 
             * @param sceneManager 
             * @param SceneType 
             * @param deltaTime 
             */
            void update(SceneManager &sceneManager, SceneType SceneType, int deltaTime) final;
        protected:
        private:
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
