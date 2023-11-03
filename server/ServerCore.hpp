/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "EntityFactory.hpp"
#include "ISystem.hpp"
#include "SceneManager.hpp"
#include "Server.hpp"

namespace ECS {
    class ServerCore {
        public:
            /**
             * @brief Construct a new ServerCore object from a server object
             * @param server
             */
            ServerCore(RType::Server &server);

            /**
             * @brief Destroy the ServerCore object
             */
            ~ServerCore() = default;

            /**
             * @brief Initialize the server's ECS
             */
            SceneManager sceneManager;

            /**
             * @brief the main loop of the ECS
             *
             */
            [[noreturn]] void mainLoop();

        private:
            /**
             * @brief Initialize the main menu scene
             *
             * @return std::shared_ptr<ECS::Scene> The main menu scene pointer
             */
            std::shared_ptr<ECS::Scene> _initMainMenuScene();
            /**
             * @brief Initialize the game scene
             * @return std::shared_ptr<ECS::Scene> The game scene pointer
             */
            std::shared_ptr<ECS::Scene> _initGameScene();

            /**
             * @brief Initialize the entities
             */
            void _initEntities();

            /**
             * @brief Initialize the handlers
             * @param packetManager
             */
            void _initHandlers(Network::PacketManager &packetManager);

            /**
             * @brief Handler for the start game instruction
             * @param packet
             * @param endpoint
             */
            void _handlerStartGame(Network::Packet &packet, const udp::endpoint &endpoint);

            /**
             * @brief Handler for the move up instruction
             * @param packet
             * @param endpoint
             */
            void _handlerMoveUp(const Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Handler for the move down instruction
             * @param packet
             * @param endpoint
             */
            void _handlerMoveDown(const Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Handler for the move left instruction
             * @param packet
             * @param endpoint
             */
            void _handlerMoveLeft(const Network::Packet &packet, const udp::endpoint &endpoint);
            /**
             * @brief Handler for the move right instruction
             * @param packet
             * @param endpoint
             */
            void _handlerMoveRight(const Network::Packet &packet, const udp::endpoint &endpoint);
            void _handlerJoin(const Network::Packet &packet, const udp::endpoint &endpoint);
            void _handlerShoot(const Network::Packet &packet, const udp::endpoint &endpoint);

            /**
             * @brief Ensure the player can move, try the given move
             * @param endpoint
             * @param x
             * @param y
             */
            void _tryMovePlayer(const udp::endpoint &endpoint, float x, float y);

            void _bossShoot();
            void _enemyShoot();

            /**
             * @brief The server's ECS systems queue
             */
            std::vector<std::unique_ptr<ECS::ISystem>> _systems;
            /**
             * @brief The server's entity factory
             */
            EntityFactory _entityFactory;
            /**
             * @brief The server object pointer
             */
            RType::Server &_server;
            /**
             * @brief The delta time between two frames, also known as the tick time
             */
            float _deltaTime = 0;
            /**
             * @brief The horizontal default speed of the entities
             */
            float _horizontalSpeed = 500;
            /**
             * @brief The vertical default speed of the entities
             */
            float _verticalSpeed = 500;
    };
}
