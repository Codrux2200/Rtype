/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ISystem.hpp"
#include "SceneManager.hpp"
#include "Connection.hpp"
#include "EntityFactory.hpp"

namespace ECS {
	/**
	 * @brief the core of the ECS
	 *
	 */
	class Core {
	    public:
            /**
             * @brief Construct a new Core object
             *
             */
            Core();
            /**
             * @brief Destroy the Core object
             *
             */
            ~Core() = default;
            /**
             * @brief a map of the system with a key string
             *
             */
            //std::map<std::string, ISystem> system;
            /**
             * @brief the actual Scene Manager
             *
             */
            SceneManager sceneManager;
            /**
             * @brief the main loop of the ECS
             *
             */
            void mainLoop(RType::Connection &connection);

        private:
            std::shared_ptr<ECS::Scene> _initMainMenuScene();
            std::shared_ptr<ECS::Scene> _initGameScene();

            void _initEntities();

            void _startGameCallback(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity);

            void _initHandlers(Network::PacketManager &packetManager);

            void _handlerStartGame(Network::Packet &packet);
            void _handlerConnect(Network::Packet &packet);

            std::vector<std::unique_ptr<ECS::ISystem>> _systems;
            EntityFactory _entityFactory;
            sf::Vector2u _modeSize;
            sf::RenderWindow _window;

            short _playerId = -1;
	};
}

#endif /* !CORE_HPP_ */
