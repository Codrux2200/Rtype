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
            ServerCore(RType::Server &server);
            ~ServerCore() = default;

            SceneManager sceneManager;

            /**
             * @brief the main loop of the ECS
             *
             */
            [[noreturn]] void mainLoop();

        private:
            std::shared_ptr<ECS::Scene> _initMainMenuScene();
            std::shared_ptr<ECS::Scene> _initGameScene();

            void _initEntities();

            void _initHandlers(Network::PacketManager &packetManager);

            void _handlerStartGame(Network::Packet &packet, const udp::endpoint &endpoint);
            
            void _handlerMoveUp(Network::Packet &packet, const udp::endpoint &endpoint);
            void _handlerMoveDown(Network::Packet &packet, const udp::endpoint &endpoint);
            void _handlerMoveLeft(Network::Packet &packet, const udp::endpoint &endpoint);
            void _handlerMoveRight(Network::Packet &packet, const udp::endpoint &endpoint);

            void _tryMovePlayer(const udp::endpoint &endpoint, float x, float y);

            std::vector<std::unique_ptr<ECS::ISystem>> _systems;
            EntityFactory _entityFactory;
            RType::Server &_server;
            float _deltaTime;
            float _horizontalSpeed = 500;
            float _verticalSpeed = 500;
    };
}
