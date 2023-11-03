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
            explicit Core(const std::string &player);
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
            /**
             * @brief init the main menu scene
             *
             * @return std::shared_ptr<ECS::Scene>
             */
            std::shared_ptr<ECS::Scene> _initMainMenuScene();
            /**
             * @brief init the game scene
             *
             * @return std::shared_ptr<ECS::Scene>
             */
            std::shared_ptr<ECS::Scene> _initGameScene();

            /**
             * @brief init the entities
             *
             */
            void _initEntities();

            /**
             * @brief Set the start game callback
             *
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
             */
            static void _startGameCallback(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity);

            /**
             * @brief init the handlers
             *
             * @param packetManager the packet manager
             */
            void _initHandlers(Network::PacketManager &packetManager);

            /**
             * @brief Set the start game handler
             *
             * @param packet the packet
             * @param endpoint the endpoint
             */
            void _handlerStartGame(Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Set the connect handler
             *
             * @param packet the packet
             * @param endpoint the endpoint
             */
            void _handlerConnect(Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Set the players pos handler
             *
             * @param packet the packet
             * @param endpoint the endpoint
             */
            void _handlerPlayersPos(Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Set the death handler
             *
             * @param packet the packet
             * @param endpoint the endpoint
             */
            void _handlerDead(Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Set the entity spawn handler
             *
             * @param packet the packet
             * @param endpoint the endpoint
             */
            void _handlerEntitySpawn(Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Set the boss state handler
             *
             * @param packet the packet
             * @param endpoint the endpoint
             */
            void _handlerBossState(Network::Packet &packet, const udp::endpoint &endpoint);

            /**
             * @brief The systems
            */
            std::vector<std::unique_ptr<ECS::ISystem>> _systems;
            /**
             * @brief The entity factory
            */
            EntityFactory _entityFactory;
            /**
             * @brief The size of the window
            */
            sf::Vector2u _modeSize;
            /**
             * @brief The window
            */
            sf::RenderWindow _window;

            short _playerId = -1;
	};
}

#endif /* !CORE_HPP_ */
