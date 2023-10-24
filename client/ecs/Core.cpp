/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include <iostream>
#include <thread>
#include "Core.hpp"
#include "PlayerComponent.hpp"
#include "PositionComponent.hpp"
#include "GraphicSystem.hpp"
#include "EventSystem.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "ClickComponent.hpp"
#include "ButtonEntity.hpp"

ECS::Core::Core() : _modeSize(800,600), _window(sf::VideoMode(_modeSize, 32), "RType & Morty")
{
    std::map<SceneType, std::shared_ptr<Scene>> scenes;

    _initEntities();
    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::MAIN_MENU, _initMainMenuScene()));
    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::GAME, _initGameScene()));
    sceneManager = SceneManager(scenes);
    _systems.push_back(std::make_unique<GraphicSystem>(_window));
    _systems.push_back(std::make_unique<EventSystem>(_window));
}

void ECS::Core::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::CONNECT, &ECS::Core::_handlerConnect);
    packetManager.REGISTER_HANDLER(Network::PacketType::START, &ECS::Core::_handlerStartGame);
    packetManager.REGISTER_HANDLER(Network::PacketType::PLAYERS_POS, &ECS::Core::_handlerPlayersPos);
}

void ECS::Core::_handlerStartGame(Network::Packet &packet, const udp::endpoint &endpoint)
{
    if (sceneManager.getSceneType() != SceneType::MAIN_MENU)
        return;
    std::cout << "Start game handler" << std::endl;
    sceneManager.setCurrentScene(SceneType::GAME);
    std::cout << "Scene type: " << sceneManager.getSceneType() << std::endl;
}

void ECS::Core::_handlerConnect(Network::Packet &packet, const udp::endpoint &endpoint)
{
    std::shared_ptr<ECS::Scene> scene = sceneManager.getScene(SceneType::GAME);

    _playerId = packet.connectData.id;
    std::cout << "Player id: " << _playerId << std::endl;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::cout << "Player " << i << ": ";
        for (int j = 0; j < NAME_LENGTH && packet.connectData.players[i][j]; j++)
            std::cout << packet.connectData.players[i][j];
        std::cout << std::endl;
        if (packet.connectData.players[i][0] == '\0') {
            std::cout << "Player " << i << " is empty" << std::endl;
            scene->getEntityByID(i)->isEnabled = false;
        }
    }
    std::shared_ptr<ECS::Entity> player = scene->getEntityByID(_playerId);
    player->addComponent(std::make_shared<ECS::PlayerComponent>(nullptr));
}

void ECS::Core::_handlerPlayersPos(Network::Packet &packet, const udp::endpoint &endpoint)
{
    auto scene = sceneManager.getScene(ECS::SceneType::GAME);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto player = scene->getEntityByID(i);
        auto positionComponent = player->getComponent<PositionComponent>();

        std::vector<int> newPos{packet.playersPos.positions[i].x, packet.playersPos.positions[i].y};

        positionComponent->setValue(newPos);
    }
}

void ECS::Core::_initEntities()
{
    // Create player
    std::shared_ptr<ECS::Entity> p1 = std::make_shared<ECS::Entity>(0);
    p1->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    p1->addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));

    sf::Texture playerTexture;

    if (!playerTexture.loadFromFile("assets/Ship6.png")) {
        std::cout << "Error loading player playerTexture" << std::endl;
        return;
    }

    sf::Rect<int> playerRect;

    playerRect.left = 0;
    playerRect.top = 0;
    playerRect.width = playerTexture.getSize().x;
    playerRect.height = playerTexture.getSize().y;

    p1->addComponent(std::make_shared<ECS::SpriteComponent>(playerTexture, playerRect));
    _entityFactory.registerEntity(p1, "player");

    // Create button
    std::shared_ptr<ECS::Entity> button = std::make_shared<ECS::ButtonEntity>();
    _entityFactory.registerEntity(button, "button");
}

std::shared_ptr<ECS::Scene> ECS::Core::_initMainMenuScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(ECS::SceneType::MAIN_MENU);
    std::shared_ptr<ECS::Entity> button = _entityFactory.createEntity("button", 4);

    std::shared_ptr<ECS::SpriteComponent> sprite = button->getComponent<ECS::SpriteComponent>();

    if (sprite == 0) {
        std::cout << "Error: sprite button is null at main menu initialization" << std::endl;
        return scene;
    }

    std::shared_ptr<ECS::PositionComponent> position = button->getComponent<ECS::PositionComponent>();

    sf::Rect<int> rect;

    if (position) {
        std::vector<int> pos = position->getValue();
        rect.left = pos.at(0);
        rect.top = pos.at(1);
    } else {
        rect.left = 0;
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

    scene->addEntity(button);
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

    _initHandlers(connection.packetManager);
    while(!sceneManager.shouldClose) {
        deltaTime = clock.restart().asSeconds();
        for (auto &system : _systems) {
            system->update(sceneManager, deltaTime, connection.sendQueue);
        }
        connection.sendPackets();
        std::this_thread::sleep_for(std::chrono::microseconds(15));
    }
}
