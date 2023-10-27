/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#include "ServerCore.hpp"
#include <thread>
#include "CollisionSystem.hpp"
#include "EnemyComponent.hpp"
#include "EnemyEntity.hpp"
#include "EntitySpawnData.hpp"
#include "HitboxComponent.hpp"
#include "PlayerBullet.hpp"
#include "PlayerComponent.hpp"
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
    _systems.push_back(std::make_unique<ECS::CollisionSystem>());
}

void ECS::ServerCore::_initEntities()
{
    std::shared_ptr<ECS::Entity> player = std::make_shared<PlayerEntity>();
    std::shared_ptr<ECS::Entity> enemy = std::make_shared<EnemyEntity>(0);
    std::shared_ptr<ECS::Entity> playerBullet = std::make_shared<PlayerBullet>(0);

    _entityFactory.registerEntity(player, "player");
    _entityFactory.registerEntity(enemy, "entity" + std::to_string(ECS::Entity::ENEMY_CLASSIC));
    _entityFactory.registerEntity(playerBullet, "entity" + std::to_string(ECS::Entity::PLAYER_BULLET));
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
    std::shared_ptr<EnemyEntity> enemy = std::make_shared<EnemyEntity>(_entityFactory.ids++);
    scene->addEntity(enemy);
    return scene;
}

[[noreturn]] void ECS::ServerCore::mainLoop()
{
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

        sceneManager.getCurrentScene()->removeEntitiesToDestroy();

        std::this_thread::sleep_for(std::chrono::milliseconds(TICK_TIME_MILLIS));
    }
}

void ECS::ServerCore::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::JOIN, &ECS::ServerCore::_handlerJoin);
    packetManager.REGISTER_HANDLER(Network::PacketType::START, &ECS::ServerCore::_handlerStartGame);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_UP, &ECS::ServerCore::_handlerMoveUp);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_DOWN, &ECS::ServerCore::_handlerMoveDown);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_LEFT, &ECS::ServerCore::_handlerMoveLeft);
    packetManager.REGISTER_HANDLER(Network::PacketType::MOVE_RIGHT, &ECS::ServerCore::_handlerMoveRight);
    packetManager.REGISTER_HANDLER(Network::PacketType::SHOOT, &ECS::ServerCore::_handlerShoot);
}

void ECS::ServerCore::_handlerShoot(const Network::Packet &packet, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    auto clientID = _server.clientManager.getClientId(endpoint);

    if (clientID == -1 || clientID > 3)
        return;

    auto scene = sceneManager.getScene(SceneType::GAME);

    auto playerEntity = scene->getEntityByID(clientID);

    if (playerEntity == nullptr)
        return;

    auto playerPositionComponent = playerEntity->getComponent<ECS::PositionComponent>();

    if (playerPositionComponent == nullptr)
        return;

    auto playerPosition = playerPositionComponent->getValue();

    auto bulletEntity = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::PLAYER_BULLET), _entityFactory.ids++);

    if (bulletEntity == nullptr)
        return;

    auto bulletPosComponent = bulletEntity->getComponent<ECS::PositionComponent>();

    if (bulletPosComponent == nullptr)
        return;

    bulletPosComponent->setValue({playerPosition[0], playerPosition[1]});

    scene->addEntity(bulletEntity);

    Network::data::EntitySpawnData data{};

    data.x = playerPosition[0];
    data.y = playerPosition[1];
    data.type = ECS::Entity::PLAYER_BULLET;
    data.id = bulletEntity->getId();

    std::cout << "-------------------------" << std::endl;
    std::cout << "BULLET ID: " << data.id << std::endl;

    auto packetToSend = Network::PacketManager::createPacket(Network::ENTITY_SPAWN, &data);

    for (const auto& cli : _server.clientManager.getClients()) {
        if (cli == nullptr)
            continue;
        _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
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

    std::shared_ptr<ECS::Scene> gameScene = sceneManager.getScene(SceneType::GAME);

    std::vector<std::shared_ptr<ECS::Entity>> enemies =
    gameScene->getEntitiesWithComponent<EnemyComponent>();

    // Sends all present enemies to the players
    for (auto &enemy : enemies) {
        Network::data::EntitySpawnData data{};
        auto positionComponent = enemy->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;
        std::vector<int> values = positionComponent->getValue();

        data.x = values[0];
        data.y = values[1];
        data.type = ECS::Entity::ENEMY_CLASSIC;
        data.id = enemy->getId();

        std::cout << "Sending enemy spawn packet" << std::endl;
        std::cout << "x: " << data.x << std::endl;
        std::cout << "y: " << data.y << std::endl;
        std::cout << "type: " << data.type << std::endl;
        std::cout << "id: " << data.id << std::endl;
        std::cout << "---------------------" << std::endl;

        auto packetToSend = Network::PacketManager::createPacket(Network::ENTITY_SPAWN, &data);

        for (const auto& cli : _server.clientManager.getClients()) {
            if (cli == nullptr)
                continue;
            _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
        }
    }
}

void ECS::ServerCore::_tryMovePlayer(const udp::endpoint &endpoint, float x, float y)
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

void ECS::ServerCore::_handlerJoin(
const Network::Packet &/* packet */, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != MAIN_MENU)
        return;

    auto gameScene = sceneManager.getScene(ECS::SceneType::GAME);

    if (gameScene == nullptr)
        return;
    int clientId = _server.clientManager.getClientId(endpoint);

    auto playerEntity = gameScene->getEntityByID(clientId);

    if (playerEntity == nullptr)
        return;

    playerEntity->isEnabled = true;

    Network::data::ConnectData connectData{};

    // Set all player names to empty
    for (auto &player : connectData.players) {
        std::memset(player, '\0', NAME_LENGTH);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = _server.clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        std::memcpy(connectData.players[i], client->getName().c_str(),
        client->getName().size());
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = _server.clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        connectData.id = i;
        std::unique_ptr<Network::Packet> connectPacket =
        Network::PacketManager::createPacket(Network::PacketType::CONNECT, &connectData);
        _server.sendPacketsQueue.emplace_back(client, *connectPacket);
    }

    _server.broadcastNewLeader();
}
