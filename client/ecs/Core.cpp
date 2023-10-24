/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include <iostream>
#include <experimental/random>
#include "Core.hpp"
#include "ControlComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
#include "RotationComponent.hpp"
#include "AudioSystem.hpp"
#include "GraphicSystem.hpp"
#include "EnemyComponent.hpp"
#include "EventSystem.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "ClickComponent.hpp"
#include "MusicsComponent.hpp"
#include "SoundComponent.hpp"

ECS::Core::Core() : _modeSize(800,600), _window(sf::VideoMode(_modeSize, 32), "RType & Morty")
{
    std::map<SceneType, std::shared_ptr<Scene>> scenes;

    _initEntities();
    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::MAIN_MENU, _initMainMenuScene()));
    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::GAME, _initGameScene()));
    if (scenes.at(SceneType::MAIN_MENU) == nullptr || scenes.at(SceneType::GAME) == nullptr) {
        std::cout << "Error: scene is null" << std::endl;
        return;
    }
    sceneManager = SceneManager(scenes);
    _systems.push_back(std::make_unique<GraphicSystem>(_window));
    _systems.push_back(std::make_unique<EventSystem>(_window));
    _systems.push_back(std::make_unique<AudioSystem>());
}

void ECS::Core::_initHandlers(Network::PacketManager &packetManager)
{
    packetManager.REGISTER_HANDLER(Network::PacketType::CONNECT, &ECS::Core::_handlerConnect);
    packetManager.REGISTER_HANDLER(Network::PacketType::START, &ECS::Core::_handlerStartGame);
}

void ECS::Core::_handlerStartGame(Network::Packet &packet)
{
    if (sceneManager.getSceneType() != SceneType::MAIN_MENU)
        return;
    std::cout << "Start game handler" << std::endl;
    sceneManager.setCurrentScene(SceneType::GAME);
    std::cout << "Scene type: " << sceneManager.getSceneType() << std::endl;
}

void ECS::Core::_handlerConnect(Network::Packet &packet)
{
    std::cout << "My new Connect handler" << std::endl;
    _playerId = packet.connectData.id;
    std::cout << "Player id: " << _playerId << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Player " << i << ": ";
        for (int j = 0; j < NAME_LENGTH && packet.connectData.players[i][j];
             j++)
            std::cout << packet.connectData.players[i][j];
        std::cout << std::endl;
    }
    // Add player Component to the player entity
    std::shared_ptr<ECS::Entity> player = sceneManager.getScene(SceneType::GAME)->entitiesList.at(_playerId);
  
    player->addComponent(std::make_shared<ECS::ControlComponent>(nullptr));
    player->addComponent(std::make_shared<ECS::MusicsComponent>("assets/sound/music.ogg"));
 
  
    // Add enemy Component to enemy entities
    int size = sceneManager.getScene(SceneType::GAME)->entitiesList.size();
    for (int i = 0; i < size; i++) {
        if (i == _playerId)
            continue;
        std::shared_ptr<ECS::Entity> enemy = sceneManager.getScene(SceneType::GAME)->entitiesList.at(i);
        if (enemy != nullptr)
            enemy->addComponent(std::make_shared<ECS::EnemyComponent>(nullptr));
    }
}

void ECS::Core::_initEntities()
{
    // Create player
    std::shared_ptr<ECS::Entity> p1 = std::make_shared<ECS::Entity>(0);
    p1->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    p1->addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));

    std::shared_ptr<sf::SoundBuffer> soundbuffer = std::make_shared<sf::SoundBuffer>();
    if(!soundbuffer->loadFromFile("assets/sound/laser.ogg")) {
        std::cerr << "Error loading sound" << std::endl;
        return;
    }
    std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>(*soundbuffer);

    p1->addComponent(std::make_shared<ECS::SoundComponent>(sound, soundbuffer));
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
    p1->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    p1->addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));
    
    p1->addComponent(std::make_shared<ECS::SpriteComponent>(playerTexture, playerRect));
    _entityFactory.registerEntity(p1, "player");

    // Create button
    std::shared_ptr<ECS::Entity> button = std::make_shared<ECS::Entity>(4);
    button->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));

    sf::Texture texture;
    if (!texture.loadFromFile("assets/start.png")) {
        std::cout << "Error loading button texture" << std::endl;
        return;
    }

    sf::Rect<int> rect;
    rect.left = 0;
    rect.top = 0;
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y;

    std::cout << "Button rect: " << rect.width << " " << rect.height << std::endl;

    button->addComponent(std::make_shared<ECS::SpriteComponent>(texture, rect));
    button->addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));
    _entityFactory.registerEntity(button, "button");

    // Create enemy
    std::shared_ptr<ECS::Entity> enemy = std::make_shared<ECS::Entity>(1);
    enemy->addComponent(std::make_shared<ECS::PositionComponent>(600, 300));
    enemy->addComponent(std::make_shared<ECS::ScaleComponent>(0.03f, 0.03f));
    enemy->addComponent(std::make_shared<ECS::RotationComponent>(270.0f));

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("assets/Ship5.png")) {
        std::cout << "Error loading enemy texture" << std::endl;
        return;
    }

    sf::Rect<int> enemyRect;
    enemyRect.left = 0;
    enemyRect.top = 0;
    enemyRect.width = enemyTexture.getSize().x;
    enemyRect.height = enemyTexture.getSize().y;
    enemy->addComponent(std::make_shared<ECS::SpriteComponent>(enemyTexture, enemyRect));
    _entityFactory.registerEntity(enemy, "enemy");
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

    button->addComponent(std::make_shared<ECS::ClickComponent>(rect, std::bind(&ECS::Core::_startGameCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _window));

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
    for (int i = 4; i < (4 + std::experimental::randint(1, 4)); i++) {
        std::shared_ptr<ECS::Entity> enemy = _entityFactory.createEntity("enemy", i);
        auto position = enemy->getComponent<ECS::PositionComponent>();
        if (position) {
            std::vector<int> pos = position->getValue();
            pos.at(0) = std::experimental::randint(400, 800);
            pos.at(1) = std::experimental::randint(70, 600);
            position->setValue(pos);
        }
        scene->addEntity(enemy);
    }
    return scene;
}

void ECS::Core::_startGameCallback(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity)
{
    std::cout << "Start game callback" << std::endl;

    Network::data::StartData startData;
    startData.mapId = 0;
    std::unique_ptr<Network::Packet> packet = packetManager.createPacket(Network::PacketType::START, &startData);
    packetsQueue.push_back(*packet);
}

void ECS::Core::mainLoop(RType::Connection &connection)
{
    // Delta time
    sf::Clock clock;
    float deltaTime = 0.0f;

    _initHandlers(connection.packetManager);
    while(!sceneManager.shouldClose) {
        deltaTime = clock.restart().asSeconds();
        for (auto &system : _systems) {
            system->update(sceneManager, deltaTime, connection.sendQueue, connection.packetManager);
        }
        for (auto &packet : connection.sendQueue) {
            connection.sendPacket(packet);
        }
        connection.sendQueue.clear();
    }
}
