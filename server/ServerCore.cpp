/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "ServerCore.hpp"
#include "PositionComponent.hpp"
#include "Server.hpp"

ECS::ServerCore::ServerCore()
{
    _initEntities();
    std::map<SceneType, std::shared_ptr<Scene>> scenes = {
        {SceneType::MAIN_MENU, _initMainMenuScene()},
        {SceneType::GAME, _initGameScene()}
    };

    sceneManager = SceneManager(scenes);
}

void ECS::ServerCore::_initEntities()
{
    std::shared_ptr<ECS::Entity> player = std::make_shared<ECS::Entity>(0);
    player->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    _entityFactory.registerEntity(player, "player");
}

std::shared_ptr<ECS::Scene> ECS::ServerCore::_initMainMenuScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(SceneType::MAIN_MENU);

    return scene;
}

std::shared_ptr<ECS::Scene> ECS::ServerCore::_initGameScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(SceneType::GAME);

    for (int i = 0; i < 4; i++) {
        std::shared_ptr<ECS::Entity> player = _entityFactory.createEntity("player", i);
        scene->addEntity(player);
    }
    return scene;
}

[[noreturn]] void ECS::ServerCore::mainLoop(RType::Server &server)
{
    std::vector<Network::Packet> packetsQueue;
    std::shared_ptr<ECS::Scene> scene = sceneManager.getScene(SceneType::GAME);
    float deltaTime = 0;

    _initHandlers(server.packetManager);
    while (true) {
        server.packetManager.executeRecvPacketsQueue();
        for (auto &system : _systems) {
            system->update(
            sceneManager, deltaTime, server.packetManager.sendPacketsQueue);
        }
        for (auto &packet : server.sendPacketsQueue) {
            server._sendMessageToClient(packet.second, packet.first->getEndpoint());
        }
    }
}

void ECS::ServerCore::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::START, &ECS::ServerCore::_handlerStartGame);
}

void ECS::ServerCore::_handlerStartGame(Network::Packet &packet)
{
    std::cout << "Start game callback" << std::endl;
}
