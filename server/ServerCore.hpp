/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "ISystem.hpp"
#include "SceneManager.hpp"
#include "EntityFactory.hpp"

namespace ECS {
    class ServerCore {
        public:
            ServerCore();
            ~ServerCore();

            SceneManager sceneManager;

            /**
             * @brief the main loop of the ECS
             *
             */
            void mainLoop(RType::Server &server);

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
    };
}