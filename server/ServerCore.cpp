/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ServerCore
*/

#define _USE_MATH_DEFINES

#include <thread>
#include <cmath>
#include "ServerCore.hpp"
#include "BossEntity.hpp"
#include "BossShootComponent.hpp"
#include "CollisionSystem.hpp"
#include "EnemyComponent.hpp"
#include "EnemyEntity.hpp"
#include "EntitySpawnData.hpp"
#include "GameSystem.hpp"
#include "PlayerBullet.hpp"
#include "PlayerComponent.hpp"
#include "PlayerEntity.hpp"
#include "PlayersPos.hpp"
#include "PositionComponent.hpp"
#include "Server.hpp"
#include "WaveSystem.hpp"
#include "VelocityComponent.hpp"
#include "BossShootEntity.hpp"
#include "EnemyBullet.hpp"
#include "EnemyBulletComponent.hpp"

ECS::ServerCore::ServerCore(RType::Server &server) : _server(server)
{
    _initEntities();
    sceneManager = SceneManager({
        {SceneType::MAIN_MENU, _initMainMenuScene()},
        {SceneType::GAME, _initGameScene()},
        {SceneType::WIN, _initWinScene()}
    });
    _systems.push_back(std::make_unique<ECS::CollisionSystem>());
    _systems.push_back(std::make_unique<ECS::GameSystem>());
    _systems.push_back(std::make_unique<ECS::WaveSystem>(_entityFactory));
}

void ECS::ServerCore::_initEntities()
{
    std::shared_ptr<ECS::Entity> player = std::make_shared<PlayerEntity>();
    std::shared_ptr<ECS::Entity> enemy = std::make_shared<EnemyEntity>(std::bind(&ECS::ServerCore::_enemyShoot, this, std::placeholders::_1, std::placeholders::_2), 0, ECS::Entity::ENEMY_CLASSIC);
    std::shared_ptr<ECS::Entity> enemyVeloce = std::make_shared<EnemyEntity>(std::bind(&ECS::ServerCore::_enemyShoot, this, std::placeholders::_1, std::placeholders::_2), 0, ECS::Entity::ENEMY_VELOCE);
    std::shared_ptr<ECS::Entity> playerBullet = std::make_shared<PlayerBullet>(0);
    std::shared_ptr<ECS::Entity> boss = std::make_shared<BossEntity>([this] { _bossShoot(); }, 0);
    std::shared_ptr<ECS::Entity> bossBullet = std::make_shared<BossShootEntity>(0);
    std::shared_ptr<ECS::Entity> enemyBullet = std::make_shared<EnemyBullet>(0);

    _entityFactory.registerEntity(player, "player");
    _entityFactory.registerEntity(enemy, "entity" + std::to_string(ECS::Entity::ENEMY_CLASSIC));
    _entityFactory.registerEntity(enemyVeloce, "entity" + std::to_string(ECS::Entity::ENEMY_VELOCE));
    _entityFactory.registerEntity(playerBullet, "entity" + std::to_string(ECS::Entity::PLAYER_BULLET));
    _entityFactory.registerEntity(boss, "entity" + std::to_string(ECS::Entity::BOSS));
    _entityFactory.registerEntity(bossBullet, "entity" + std::to_string(ECS::Entity::BOSS_BULLET));
    _entityFactory.registerEntity(enemyBullet, "entity" + std::to_string(ECS::Entity::ENEMY_BULLET));
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
        std::cout << "Player " << player->getId() << " created" << std::endl;
        scene->addEntity(player);
    }
    // Hardcoded shit
//    std::shared_ptr<ECS::Entity> enemy = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::ENEMY_CLASSIC), _entityFactory.ids++);
//    scene->addEntity(enemy);
//    std::shared_ptr<ECS::Entity> enemy_veloce = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::ENEMY_VELOCE), _entityFactory.ids++);
//    scene->addEntity(enemy_veloce);
//    std::shared_ptr<ECS::Entity> boss = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::BOSS), _entityFactory.ids++);
//    scene->addEntity(boss);
    return scene;
}

[[noreturn]] void ECS::ServerCore::mainLoop()
{
    // Initialize variables for delta time calculation.
    auto lastFrameTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> frameDuration{};
    std::chrono::milliseconds waitTime{};

    _initHandlers(_server.packetManager);
    while (true) {
        frameDuration = std::chrono::high_resolution_clock::now() - lastFrameTime;
        _deltaTime = frameDuration.count();
        lastFrameTime = std::chrono::high_resolution_clock::now();

        if (sceneManager.getSceneType() == ECS::SceneType::GAME || sceneManager.getSceneType() == ECS::SceneType::WIN) {
            int score = sceneManager.getCurrentScene()->removeEntitiesToDestroy(_deltaTime);

            Network::data::ScoreData Score {};
            Score.Score = score;
            auto packetToSend = Network::PacketManager::createPacket(Network::SCORE, &Score);
            for (const auto &cli : _server.clientManager.getClients()) {
                if (cli == nullptr)
                    continue;
                _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
            }
        }

        _server.packetManager.executeRecvPacketsQueue();
        for (auto &system : _systems) {
            if (system == nullptr)
                continue;
            system->update(
            sceneManager, _deltaTime, _server.packetManager.sendPacketsQueue);
        }
        _server.sendPackets();

        waitTime = std::chrono::milliseconds(TICK_TIME_MILLIS - std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastFrameTime).count());
        if (waitTime.count() > 0)
            std::this_thread::sleep_for(waitTime);
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

    if (clientID == -1 || clientID > 3) {
        std::cerr << "Invalid client ID: " << clientID << std::endl;
        return;
    }

    auto scene = sceneManager.getScene(SceneType::GAME);
    auto playerEntity = scene->getEntityByID(clientID);

    if (playerEntity == nullptr)
        return;

    auto playerPositionComponent = playerEntity->getComponent<ECS::PositionComponent>();
    auto playerComponent = playerEntity->getComponent<ECS::PlayerComponent>();

    if (playerPositionComponent == nullptr || playerComponent == nullptr)
        return;

    if (playerComponent->getLastFire() < playerComponent->fireRate) {
        return;
    }

    auto playerPosition = playerPositionComponent->getValue();

    auto bulletEntity = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::PLAYER_BULLET), _entityFactory.ids++);

    if (bulletEntity == nullptr)
        return;

    auto bulletPosComponent = bulletEntity->getComponent<ECS::PositionComponent>();
    auto velocityComponent = bulletEntity->getComponent<ECS::VelocityComponent>();
    if (bulletPosComponent == nullptr || velocityComponent == nullptr)
        return;

    playerComponent->resetLastFire();
    bulletPosComponent->x = playerPosition[0] + 50;
    bulletPosComponent->y = playerPosition[1] + 50;

    scene->addEntity(bulletEntity);

    Network::data::EntitySpawnData data{};

    data.x = playerPosition[0];
    data.y = playerPosition[1];
    data.vx = velocityComponent->vx;
    data.vy = velocityComponent->vy;
    data.type = ECS::Entity::PLAYER_BULLET;
    data.id = bulletEntity->getId();

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
        if (enemy == nullptr)
            continue;
        Network::data::EntitySpawnData data{};
        auto positionComponent = enemy->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;
        std::vector<int> values = positionComponent->getValue();

        data.x = static_cast<int>(positionComponent->x);
        data.y = static_cast<int>(positionComponent->y);
        data.type = enemy->getComponent<EnemyComponent>()->getEnemyType();
        data.id = enemy->getId();

        std::cout << "Sending enemy spawn packet" << std::endl;
        std::cout << "x: " << positionComponent->x << std::endl;
        std::cout << "y: " << positionComponent->y << std::endl;
        std::cout << "type: " << (int) data.type << std::endl;
        std::cout << "id: " << data.id << std::endl;
        std::cout << "---------------------" << std::endl;

        auto packetToSend = Network::PacketManager::createPacket(Network::ENTITY_SPAWN, &data);

        for (const auto& cli : _server.clientManager.getClients()) {
            if (cli == nullptr)
                continue;
            _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
        }
    }

    std::vector<std::shared_ptr<ECS::Entity>> bosses =
    gameScene->getEntitiesWithComponent<BossComponent>();

    // Sends all present bosses to the players
    for (auto &boss : bosses) {
        if (boss == nullptr)
            continue;
        Network::data::EntitySpawnData data{};
        auto positionComponent = boss->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;
        std::vector<int> values = positionComponent->getValue();

        data.x = static_cast<int>(positionComponent->x);
        data.y = static_cast<int>(positionComponent->y);
        data.type = ECS::Entity::BOSS;
        data.id = boss->getId();

        std::cout << "Sending boss spawn packet" << std::endl;
        std::cout << "x: " << positionComponent->x << std::endl;
        std::cout << "y: " << positionComponent->y << std::endl;
        std::cout << "type: " << (int) data.type << std::endl;
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

    position->move(x, y);

    if (position->x < 0)
        position->move(-position->x, 0);
    if (position->x > 720)
        position->move(720 - position->x, 0);
    if (position->y < 0)
        position->move(0, -position->y);
    if (position->y > 540)
        position->move(0, 540 - position->y);

    Network::data::PlayersPos data{};

    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::shared_ptr<Entity> cli = scene->getEntityByID(i);

        if (cli == nullptr)
            continue;
        auto positionComponent = cli->getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            continue;

        data.positions[i] = {static_cast<int>(positionComponent->x), static_cast<int>(positionComponent->y)};
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

void ECS::ServerCore::_bossShoot()
{
    auto gameScene = sceneManager.getScene(ECS::SceneType::GAME);
    auto bossEntities = gameScene->getEntitiesWithComponent<ECS::BossComponent>();

    if (bossEntities.empty())
        return;

    auto bossEntity = bossEntities[0];

    if (bossEntity == nullptr)
        return;

    auto bossPosComponent = bossEntity->getComponent<ECS::PositionComponent>();

    if (bossPosComponent == nullptr)
        return;

    // Summon 10 boss bullets in a half circle
    for (int i = 0; i < 10; i++) {
        auto bulletEntity = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::BOSS_BULLET), _entityFactory.ids++);

        if (bulletEntity == nullptr)
            return;

        auto bulletPosComponent = bulletEntity->getComponent<ECS::PositionComponent>();
        auto bulletComponent = bulletEntity->getComponent<ECS::BossShootComponent>();
        auto bulletVelocityComponent = bulletEntity->getComponent<ECS::VelocityComponent>();

        if (bulletPosComponent == nullptr || bulletComponent == nullptr || bulletVelocityComponent == nullptr)
            return;

        bulletPosComponent->x = bossPosComponent->x;
        bulletPosComponent->y = bossPosComponent->y + 200;

        bulletVelocityComponent->vx = static_cast<float>(-std::cos((i * 18) * 3.14 / 180) * 500);
        bulletVelocityComponent->vy = static_cast<float>(std::sin((i * 18) * 3.14 / 180) * 500);

        gameScene->addEntity(bulletEntity);

        Network::data::EntitySpawnData data{};

        data.x = static_cast<int>(bulletPosComponent->x);
        data.y = static_cast<int>(bulletPosComponent->y);
        data.vx = bulletVelocityComponent->vx;
        data.vy = bulletVelocityComponent->vy;
        data.type = ECS::Entity::BOSS_BULLET;
        data.id = bulletEntity->getId();

        auto packetToSend = Network::PacketManager::createPacket(Network::ENTITY_SPAWN, &data);

        for (const auto& cli : _server.clientManager.getClients())
            if (cli != nullptr)
                _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
    }
}

void ECS::ServerCore::_enemyShoot(int x, int y)
{
    auto gameScene = sceneManager.getScene(ECS::SceneType::GAME);
    auto enemies = gameScene->getEntitiesWithComponent<ECS::EnemyComponent>();

    if (enemies.empty())
        return;

    // Summon 1 bullet
    auto bulletEntity = _entityFactory.createEntity("entity" + std::to_string(ECS::Entity::ENEMY_BULLET), _entityFactory.ids++);

    if (bulletEntity == nullptr)
        return;

    auto bulletPosComponent = bulletEntity->getComponent<ECS::PositionComponent>();
    auto bulletComponent = bulletEntity->getComponent<ECS::EnemyBulletComponent>();
    auto bulletVelocityComponent = bulletEntity->getComponent<ECS::VelocityComponent>();

    if (bulletPosComponent == nullptr || bulletComponent == nullptr || bulletVelocityComponent == nullptr)
        return;

    bulletPosComponent->x = x - 20;
    bulletPosComponent->y = y;

    bulletVelocityComponent->vx = -200;
    bulletVelocityComponent->vy = 0;

    gameScene->addEntity(bulletEntity);

    Network::data::EntitySpawnData data{};

    data.x = static_cast<int>(bulletPosComponent->x);
    data.y = static_cast<int>(bulletPosComponent->y);
    data.vx = bulletVelocityComponent->vx;
    data.vy = bulletVelocityComponent->vy;
    data.type = ECS::Entity::ENEMY_BULLET;
    data.id = bulletEntity->getId();

    auto packetToSend = Network::PacketManager::createPacket(Network::ENTITY_SPAWN, &data);

    for (const auto& cli : _server.clientManager.getClients())
        if (cli != nullptr)
            _server.sendPacketsQueue.emplace_back(cli, *packetToSend);
}

std::shared_ptr<ECS::Scene> ECS::ServerCore::_initWinScene()
{
    return std::make_shared<ECS::Scene>(SceneType::WIN);
}
