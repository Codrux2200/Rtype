/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EventSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "ISystem.hpp"
#include "Connection.hpp"
#include "PositionComponent.hpp"
#include "Entity.hpp"
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
    class EventSystem : public ISystem {
        public:

            /**
             * @brief Construct a new Event System object
             *
             */
            EventSystem(sf::RenderWindow &window);

            /**
             * @brief update the event system
             *
             * @param sceneManager
             * @param SceneType
             * @param deltaTime
             */
            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;

        private:
            sf::Event _event;
            sf::RenderWindow &_window;
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
