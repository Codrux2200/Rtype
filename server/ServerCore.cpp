/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "ServerCore.hpp"
#include "PositionComponent.hpp"
#include "Server.hpp"
#include "PlayersPos.hpp"

ECS::ServerCore::ServerCore(RType::Server &server) : _server(server)
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

[[noreturn]] void ECS::ServerCore::mainLoop()
{
    std::vector<Network::Packet> packetsQueue;
    std::shared_ptr<ECS::Scene> scene = sceneManager.getScene(SceneType::GAME);
    float deltaTime = 0;

    _initHandlers(_server.packetManager);
    while (true) {
        _server.packetManager.executeRecvPacketsQueue();
        for (auto &system : _systems) {
            system->update(
            sceneManager, deltaTime, _server.packetManager.sendPacketsQueue);
        }
        _server.sendPackets();
    }
}

void ECS::ServerCore::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::START, &ECS::ServerCore::_handlerStartGame);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_UP, &ECS::ServerCore::_handlerMoveUp);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_DOWN, &ECS::ServerCore::_handlerMoveDown);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_LEFT, &ECS::ServerCore::_handlerMoveLeft);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_RIGHT, &ECS::ServerCore::_handlerMoveRight);
}

void ECS::ServerCore::_handlerStartGame(Network::Packet &packet, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != MAIN_MENU)
        return;
    auto client = _server.clientManager.getClientByEndpoint(endpoint);
    auto leader = _server.clientManager.getLeader();

    if (leader == nullptr || client == nullptr || leader->getEndpoint() != client->getEndpoint())
        return;
    sceneManager.setCurrentScene(SceneType::GAME);
    for (const auto& cli : _server.clientManager.getClients()) {
        if (cli == nullptr)
            continue;
        _server.sendPacketsQueue.emplace_back(cli, packet);
    }
}

void ECS::ServerCore::_handlerMoveUp(Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    auto client = _server.clientManager.getClientByEndpoint(endpoint);
    std::shared_ptr<Scene> scene = sceneManager.getScene(SceneType::GAME);
    auto entity = scene->getEntityByID(_server.clientManager.getClientId(client->getEndpoint()));

    if (entity == nullptr)
        return;
    auto position = entity->getComponent<PositionComponent>();
    auto pos = position->getValue();

    if (pos[1] <= 0)
        return;
    position->move(0, -1);

    Network::data::PlayersPos data{};

    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::shared_ptr<Entity> cli = scene->getEntityByID(i);

        if (cli == nullptr)
            continue;
        auto positionComponent = cli->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;

        std::vector<int> values = positionComponent->getValue();

        data.positions[i] = {values[0], values[1]};
    }
    auto packetToSend = Network::PacketManager::createPacket(Network::PLAYERS_POS, &data);

    for (auto cli : _server.clientManager.getClients()) {
        _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
}

void ECS::ServerCore::_handlerMoveDown(Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    auto client = _server.clientManager.getClientByEndpoint(endpoint);
    std::shared_ptr<Scene> scene = sceneManager.getScene(SceneType::GAME);
    auto entity = scene->getEntityByID(_server.clientManager.getClientId(client->getEndpoint()));

    if (entity == nullptr)
        return;
    auto position = entity->getComponent<PositionComponent>();
    auto pos = position->getValue();

    if (pos[1] >= 540)
        return;
    position->move(0, 1);

    Network::data::PlayersPos data{};

    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::shared_ptr<Entity> cli = scene->getEntityByID(i);

        if (cli == nullptr)
            continue;
        auto positionComponent = cli->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;

        std::vector<int> values = positionComponent->getValue();

        data.positions[i] = {values[0], values[1]};
    }
    auto packetToSend = Network::PacketManager::createPacket(Network::PLAYERS_POS, &data);

    for (auto cli : _server.clientManager.getClients()) {
        _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
}

void ECS::ServerCore::_handlerMoveLeft(Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    auto client = _server.clientManager.getClientByEndpoint(endpoint);
    std::shared_ptr<Scene> scene = sceneManager.getScene(SceneType::GAME);
    auto entity = scene->getEntityByID(_server.clientManager.getClientId(client->getEndpoint()));

    if (entity == nullptr)
        return;
    auto position = entity->getComponent<PositionComponent>();
    auto pos = position->getValue();

    if (pos[0] <= 0)
        return;
    position->move(-1, 0);

    Network::data::PlayersPos data{};

    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::shared_ptr<Entity> cli = scene->getEntityByID(i);

        if (cli == nullptr)
            continue;
        auto positionComponent = cli->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;

        std::vector<int> values = positionComponent->getValue();

        data.positions[i] = {values[0], values[1]};
    }
    auto packetToSend = Network::PacketManager::createPacket(Network::PLAYERS_POS, &data);

    for (auto cli : _server.clientManager.getClients()) {
        _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
}

void ECS::ServerCore::_handlerMoveRight(Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    auto client = _server.clientManager.getClientByEndpoint(endpoint);
    std::shared_ptr<Scene> scene = sceneManager.getScene(SceneType::GAME);
    auto entity = scene->getEntityByID(_server.clientManager.getClientId(client->getEndpoint()));

    if (entity == nullptr)
        return;
    auto position = entity->getComponent<PositionComponent>();
    auto pos = position->getValue();

    if (pos[0] >= 720)
        return;
    position->move(1, 0);

    Network::data::PlayersPos data{};

    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::shared_ptr<Entity> cli = scene->getEntityByID(i);

        if (cli == nullptr)
            continue;
        auto positionComponent = cli->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;

        std::vector<int> values = positionComponent->getValue();

        data.positions[i] = {values[0], values[1]};
    }
    auto packetToSend = Network::PacketManager::createPacket(Network::PLAYERS_POS, &data);

    for (auto cli : _server.clientManager.getClients()) {
        _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
}
