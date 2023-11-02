/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>
#include <thread>
#include "AudioSystem.hpp"
#include "ButtonEntity.hpp"
#include "ClickComponent.hpp"
#include "ControlComponent.hpp"
#include "EnemyEntity.hpp"
#include "EventSystem.hpp"
#include "GameSystem.hpp"
#include "GraphicSystem.hpp"
#include "MusicsComponent.hpp"
#include "PlayerBullet.hpp"
#include "PlayerEntity.hpp"
#include "PositionComponent.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "ConvertPath.hpp"
#include "StaticBackgroundEntity.hpp"
#include "TextComponent.hpp"
#include "VelocityComponent.hpp"
#include "BossEntity.hpp"
#include "BossShootEntity.hpp"

ECS::Core::Core(const std::string &player) : _modeSize(800,600), _window(sf::VideoMode(_modeSize, 32), "RType & Morty - " + player)
{
    std::map<SceneType, std::shared_ptr<Scene>> scenes;

    _initEntities();
    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::MAIN_MENU, _initMainMenuScene()));
    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::GAME, _initGameScene()));
    if (scenes.at(SceneType::MAIN_MENU) == nullptr || scenes.at(SceneType::GAME) == nullptr) {
        std::cerr << "Error: scene is null" << std::endl;
        return;
    }
    sceneManager = SceneManager(scenes);
    _systems.push_back(std::make_unique<GraphicSystem>(_window));
    _systems.push_back(std::make_unique<EventSystem>(_window));
    _systems.push_back(std::make_unique<AudioSystem>());
    _systems.push_back(std::make_unique<GameSystem>());
}

void ECS::Core::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::CONNECT, &ECS::Core::_handlerConnect);
    packetManager.REGISTER_HANDLER(Network::PacketType::START, &ECS::Core::_handlerStartGame);
    packetManager.REGISTER_HANDLER(Network::PacketType::PLAYERS_POS, &ECS::Core::_handlerPlayersPos);
    packetManager.REGISTER_HANDLER(Network::PacketType::DEAD, &ECS::Core::_handlerDead);
    packetManager.REGISTER_HANDLER(Network::PacketType::ENTITY_SPAWN, &ECS::Core::_handlerEntitySpawn);
    packetManager.REGISTER_HANDLER(Network::PacketType::BOSS_STATE, &ECS::Core::_handlerBossState);
}

void ECS::Core::_handlerStartGame(Network::Packet &packet, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != SceneType::MAIN_MENU)
        return;
    std::cout << "Start game handler" << std::endl;
    sceneManager.getCurrentScene()->getEntityByID(4)->getComponent<ECS::MusicsComponent>()->stop();
    sceneManager.setCurrentScene(SceneType::GAME);
    std::cout << "Scene type: " << sceneManager.getSceneType() << std::endl;
}

void ECS::Core::_handlerConnect(Network::Packet &packet, const udp::endpoint &endpoint)
{
    std::shared_ptr<ECS::Scene> scene = sceneManager.getScene(SceneType::GAME);

    _playerId = packet.connectData.id;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (packet.connectData.players[i][0] == '\0') {
            scene->getEntityByID(i)->isEnabled = false;
        } else {
            scene->getEntityByID(i)->isEnabled = true;
        }
    }
    // Add player Component to the player entity
    std::shared_ptr<ECS::Entity> player = sceneManager.getScene(SceneType::GAME)->entitiesList.at(_playerId);
  
    player->addComponent(std::make_shared<ECS::ControlComponent>());
    player->addComponent(std::make_shared<ECS::MusicsComponent>(ConvertPath::convertPath("assets/sound/music.ogg")));
}

void ECS::Core::_handlerPlayersPos(Network::Packet &packet, const udp::endpoint &endpoint)
{
    auto scene = sceneManager.getScene(ECS::SceneType::GAME);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto player = scene->getEntityByID(i);
        auto positionComponent = player->getComponent<PositionComponent>();

        positionComponent->x = packet.playersPos.positions[i].x;
        positionComponent->y = packet.playersPos.positions[i].y;
    }
}

void ECS::Core::_handlerDead(Network::Packet &packet, const udp::endpoint &endpoint)
{
    auto scene = sceneManager.getScene(ECS::SceneType::GAME);

    std::cout << "Handler dead" << std::endl;
    auto entity = scene->getEntityByID(packet.deadData.id);
    if (entity == nullptr)
        return;
    entity->isEnabled = false;
    entity->deathReason = packet.deadData.reason;

    if (packet.deadData.id == _playerId) {
        std::cout << "Player is dead" << std::endl;
    }
}

void ECS::Core::_initEntities()
{
    std::shared_ptr<ECS::Entity> p1 = std::make_shared<ECS::PlayerEntity>(0);
    _entityFactory.registerEntity(p1, "player");

    // Create button
    std::shared_ptr<ECS::Entity> back = std::make_shared<ECS::StaticBackgroundEntity>("assets/back.png");
    _entityFactory.registerEntity(back, "background");
    std::shared_ptr<ECS::Entity> button = std::make_shared<ECS::ButtonEntity>("assets/startgame.png", 0, 300);
    _entityFactory.registerEntity(button, "buttonStart");
    std::shared_ptr<ECS::Entity> buttonStop = std::make_shared<ECS::ButtonEntity>("assets/options.png", 0 , 200);
    _entityFactory.registerEntity(buttonStop, "buttonStop");
    std::shared_ptr<ECS::Entity> text = std::make_shared<ECS::Entity>(1);
    text->addComponent(std::make_shared<ECS::TextComponent>("bonjour"));
    _entityFactory.registerEntity(text, "text");
    // Create enemy
    std::shared_ptr<ECS::Entity> enemy = std::make_shared<EnemyEntity>(0);
    _entityFactory.registerEntity(enemy, "entity" + std::to_string(ECS::Entity::EntityType::ENEMY_CLASSIC));
    // Create player bullet
    std::shared_ptr<ECS::Entity> playerBullet = std::make_shared<ECS::PlayerBullet>(0);
    _entityFactory.registerEntity(playerBullet, "entity" + std::to_string(ECS::Entity::EntityType::PLAYER_BULLET));

    // Create boss
    std::shared_ptr<ECS::Entity> boss = std::make_shared<BossEntity>(0);
    _entityFactory.registerEntity(boss, "entity" + std::to_string(ECS::Entity::EntityType::BOSS));

    // Create boss bullet
    std::shared_ptr<ECS::Entity> bossBullet = std::make_shared<BossShootEntity>(0);
    _entityFactory.registerEntity(bossBullet, "entity" + std::to_string(ECS::Entity::EntityType::BOSS_BULLET));
}

std::shared_ptr<ECS::Scene> ECS::Core::_initMainMenuScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(ECS::SceneType::MAIN_MENU);
    std::shared_ptr<ECS::Entity> button = _entityFactory.createEntity("buttonStart", _entityFactory.ids++);
    std::shared_ptr<ECS::Entity> background = _entityFactory.createEntity("background", _entityFactory.ids++);
    std::shared_ptr<ECS::Entity> buttonStop = _entityFactory.createEntity("buttonStop", _entityFactory.ids++);
    std::shared_ptr<ECS::Entity> text = _entityFactory.createEntity("text", _entityFactory.ids++);
    std::shared_ptr<ECS::SpriteComponent> sprite = button->getComponent<ECS::SpriteComponent>();
    if (sprite == nullptr) {
        std::cout << "Error: sprite button is null at main menu initialization" << std::endl;
        return scene;
    }
    std::shared_ptr<ECS::SpriteComponent> spriteStop = buttonStop->getComponent<ECS::SpriteComponent>();
    if (spriteStop == nullptr) {
        std::cout << "Error: sprite button is null at main menu initialization" << std::endl;
        return scene;
    }
    std::shared_ptr<ECS::TextComponent> textComponent = text->getComponent<ECS::TextComponent>();

    textComponent->setPosition(100, 500);
    scene->addEntity(background);
    scene->addEntity(text);

    std::shared_ptr<ECS::PositionComponent> position = button->getComponent<ECS::PositionComponent>();

    sf::Rect<int> rect;

    if (position) {
        std::vector<int> pos = position->getValue();
        rect.left = pos.at(0);
        rect.top = pos.at(1);
    } else {
        rect.left = 100;
        rect.top = 0;
    }

    std::shared_ptr<ECS::ScaleComponent> scale = button->getComponent<ECS::ScaleComponent>();

    if (scale) {
        std::vector<float> scaleValue = scale->getFloatValue();
        rect.width = sprite->getRect().width * scaleValue.at(0);
        rect.height = sprite->getRect().height * scaleValue.at(1);
    } else {
        rect.width = sprite->getRect().width;
        rect.height = sprite->getRect().height;
    }

    button->addComponent(std::make_shared<ECS::ClickComponent>(rect, std::bind(&_startGameCallback, std::placeholders::_1, std::placeholders::_2), _window));
    button->addComponent(std::make_shared<ECS::MusicsComponent>("assets/sound/Main_Menu.ogg"));


    scene->addEntity(button);
    scene->addEntity(buttonStop);
    return scene;
}

std::shared_ptr<ECS::Scene> ECS::Core::_initGameScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(ECS::SceneType::GAME);

    for (int i = 0; i < 4; i++) {
        std::shared_ptr<ECS::Entity> player = _entityFactory.createEntity("player", i);
        scene->addEntity(player);
    }
    return scene;
}

void ECS::Core::_startGameCallback(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity)
{
    std::cout << "Start game callback" << std::endl;

    Network::data::StartData startData{};
    startData.mapId = 0;
    std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::START, &startData);
    packetsQueue.push_back(*packet);
}

void ECS::Core::mainLoop(RType::Connection &connection)
{
    // Delta time
    sf::Clock clock;
    float deltaTime;
    std::chrono::milliseconds waitTime;

    _initHandlers(connection.packetManager);
    while(!sceneManager.shouldClose) {
        deltaTime = clock.restart().asSeconds();
        connection.handlePackets();
        for (auto &system : _systems) {
            if (system == nullptr)
                continue;
            system->update(sceneManager, deltaTime, connection.packetManager.sendPacketsQueue);
        }
        connection.sendPackets();
        sceneManager.getCurrentScene()->removeEntitiesToDestroy(deltaTime);

        waitTime = std::chrono::milliseconds(TICK_TIME_MILLIS - clock.getElapsedTime().asMilliseconds());
        if (waitTime.count() > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    }
}

void ECS::Core::_handlerEntitySpawn(
Network::Packet &packet, const udp::endpoint &endpoint)
{
    std::string entityType = "entity" + std::to_string(packet.entitySpawnData.type);
    std::shared_ptr<ECS::Entity> entity = _entityFactory.createEntity(entityType, packet.entitySpawnData.id);

    if (entity == nullptr) {
        return;
    }
    auto positionComponent = entity->getComponent<ECS::PositionComponent>();
    auto velocityComponent = entity->getComponent<ECS::VelocityComponent>();

    if (positionComponent == nullptr || velocityComponent == nullptr) {
        return;
    }
    positionComponent->x = (packet.entitySpawnData.x);
    positionComponent->y = (packet.entitySpawnData.y);
    velocityComponent->vx = packet.entitySpawnData.vx;
    velocityComponent->vy = packet.entitySpawnData.vy;
    auto scene = sceneManager.getScene(ECS::SceneType::GAME);

    if (scene == nullptr)
        return;
    std::cout << "Entity spawned: " << entityType << std::endl;
    scene->addEntity(entity);
}

void ECS::Core::_handlerBossState(
Network::Packet &packet, const udp::endpoint &endpoint)
{
    auto scene = sceneManager.getScene(ECS::SceneType::GAME);

    if (scene == nullptr)
        return;
    auto boss = scene->getEntityByID(packet.bossStateData.id);

    if (boss == nullptr)
        return;

    auto bossComponent = boss->getComponent<BossComponent>();

    if (bossComponent == nullptr)
        return;
    bossComponent->setState(packet.bossStateData.state, packet.bossStateData.isUp);

    auto positionComponent = boss->getComponent<PositionComponent>();

    if (positionComponent == nullptr)
        return;
    positionComponent->x = packet.bossStateData.x;
    positionComponent->y = packet.bossStateData.y;
}
