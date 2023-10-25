/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "ServerCore.hpp"
#include <thread>
#include "HitboxComponent.hpp"
#include "PlayerEntity.hpp"
#include "PlayersPos.hpp"
#include "PositionComponent.hpp"
#include "Server.hpp"

ECS::ServerCore::ServerCore(RType::Server &server) : _server(server)
{
    _initEntities();
    sceneManager = SceneManager({
        {SceneType::MAIN_MENU, _initMainMenuScene()},
        {SceneType::GAME, _initGameScene()}
    });
}

void ECS::ServerCore::_initEntities()
{
    std::shared_ptr<ECS::Entity> player = std::make_shared<PlayerEntity>();


    std::shared_ptr<ECS::Entity> enemy = std::make_shared<ECS::Entity>(0);
    enemy->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
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
    // Initialize variables for delta time calculation.
    std::chrono::high_resolution_clock clock;
    auto lastFrameTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> frameDuration{};

    _initHandlers(_server.packetManager);
    while (true) {
        frameDuration = std::chrono::high_resolution_clock::now() - lastFrameTime;
        _deltaTime = frameDuration.count();
        lastFrameTime = std::chrono::high_resolution_clock::now();

        _server.packetManager.executeRecvPacketsQueue();
        for (auto &system : _systems) {
            system->update(
            sceneManager, _deltaTime, _server.packetManager.sendPacketsQueue);
        }
        _server.sendPackets();
        std::this_thread::sleep_for(std::chrono::milliseconds(TICK_TIME_MILLIS));
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

void ECS::ServerCore::_tryMovePlayer(const udp::endpoint &endpoint, float x, float y)
{
    std::cout << "Trying to move player" << std::endl;
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    auto client = _server.clientManager.getClientByEndpoint(endpoint);
    std::shared_ptr<Scene> scene = sceneManager.getScene(SceneType::GAME);
    auto entity = scene->getEntityByID(_server.clientManager.getClientId(client->getEndpoint()));

    if (entity == nullptr)
        return;

    std::cout << "Check player pos" << std::endl;
    auto position = entity->getComponent<PositionComponent>();
    auto pos = position->getValue();

    position->move(x, y);

    pos = position->getValue();
    if (pos[0] < 0)
        position->move(-pos[0], 0);
    if (pos[0] > 720)
        position->move(720 - pos[0], 0);
    if (pos[1] < 0)
        position->move(0, -pos[1]);
    if (pos[1] > 540)
        position->move(0, 540 - pos[1]);

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

    for (const auto& cli : _server.clientManager.getClients()) {
        if (cli == nullptr)
            continue;
        _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
    std::cout << "Player moved" << std::endl;
}

void ECS::ServerCore::_handlerMoveUp(const Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    _tryMovePlayer(endpoint, 0, -(_verticalSpeed * _deltaTime));
}

void ECS::ServerCore::_handlerMoveDown(const Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    _tryMovePlayer(endpoint, 0, _verticalSpeed * _deltaTime);
}

void ECS::ServerCore::_handlerMoveLeft(const Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    _tryMovePlayer(endpoint, -(_horizontalSpeed * _deltaTime), 0);
}

void ECS::ServerCore::_handlerMoveRight(const Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    _tryMovePlayer(endpoint, _horizontalSpeed * _deltaTime, 0);
}
