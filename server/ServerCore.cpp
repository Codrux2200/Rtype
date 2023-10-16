/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "ServerCore.hpp"

ECS::ServerCore::ServerCore()
{
    _initEntities();
    std::map<SceneType, std::shared_ptr<Scene>> scenes = {
        {SceneType::MAIN_MENU, _initMainMenuScene()},
        {SceneType::GAME, _initGameScene()}
    };

    sceneManager = SceneManager(scenes);
}

ECS::ServerCore::~ServerCore()
{
}

void ECS::ServerCore::_initEntities()
{
    std::shared_ptr<ECS::Entity> player = std::make_shared<ECS::Entity>(0);
    player->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    _entityFactory.registerEntity("player", player);
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

void ECS::ServerCore::mainLoop(RType::Server &server)
{
    std::vector<Network::Packet> packetsQueue;
    std::shared_ptr<ECS::Scene> scene = sceneManager.getScene(SceneType::GAME);
    std::vector<std::shared_ptr<ECS::Entity>> entities = scene->getEntities();

    _initHandlers(server.packetManager);
    while (true) {
        packetsQueue = server.getPacketsQueue();
        for (auto &packet : packetsQueue) {
            packetManager.handlePacket(packet);
        }
        for (auto &entity : entities) {
            for (auto &system : _systems) {
                system->update(entity);
            }
        }
        server.sendPacketsQueue();
    }
}

void ECS::ServerCore::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::START, );
    packetManager.REGISTER_HANDLER();
}