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
            GraphicSystem(sf::RenderWindow &window);
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
            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue, Network::PacketManager &packetManager) override;

        private:
            sf::Event _event;
            BackgroundComponent backgroundComponent;

            sf::RenderWindow &_window;

    };
};
#endif /* !GRAPHICSYSTEM_HPP_ */
