/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "ISystem.hpp"
#include "BackgroundComponent.hpp"
#include <SFML/Graphics.hpp>

namespace ECS {
    /**
     * @brief Graphic System
     *
     */
    class GraphicSystem : public ISystem {
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

            void initBackground();

            /**
             * @brief update the Graphic System
             *
             * @param sceneManager
             * @param SceneType
             * @param deltaTime
             */
            void update(SceneManager &sceneManager, int deltaTime, std::vector<Network::Packet> &packetQueue, Network::PacketManager &packetManager) override;
            /**
             * @brief Get the Window object
             *
             * @return sf::RenderWindow
             */
            sf::RenderWindow &getWindow();

        private:
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Vector2u _modeSize;
            BackgroundComponent backgroundComponent;


    };
};
#endif /* !GRAPHICSYSTEM_HPP_ */
