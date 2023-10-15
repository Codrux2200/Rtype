/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include <experimental/random>
#include "Core.hpp"
#include "PlayerComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
#include "RotationComponent.hpp"
#include "GraphicSystem.hpp"
#include "EventSystem.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "ClickComponent.hpp"

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
}

void ECS::Core::_initHandlers(Network::PacketManager &packetManager)
{
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

    button->addComponent(std::make_shared<ECS::ClickComponent>(rect, std::bind(&ECS::Core::_startGameCallback, this, std::placeholders::_1, std::placeholders::_2), _window));

    scene->addEntity(button);
    return scene;
}

std::shared_ptr<ECS::Scene> ECS::Core::_initGameScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(ECS::SceneType::GAME);

    for (int i = 0; i < 4; i++) {
        std::shared_ptr<ECS::Entity> player = _entityFactory.createEntity("player", i);
        if (i == _playerId) {
            // This is the current player !
            player->addComponent(std::make_shared<ECS::PlayerComponent>());
        }
        scene->addEntity(player);
    }
    for (int i = 0; i < 4; i++) {
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

void ECS::Core::_startGameCallback(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue)
{
    std::cout << "Start game callback" << std::endl;

    Network::data::StartData startData;
    startData.mapId = 0;
    std::unique_ptr<Network::Packet> packet = packetManager.createPacket(Network::PacketType::START, &startData);
    packetsQueue.push_back(*packet);
}

void ECS::Core::mainLoop(RType::Connection &connection)
{
    int deltaTime = 0;

    _initHandlers(connection.packetManager);
    while(!sceneManager.shouldClose) {
        for (auto &system : _systems) {
            system->update(sceneManager, deltaTime, connection.sendQueue, connection.packetManager);
        }
        for (auto &packet : connection.sendQueue) {
            connection.sendPacket(packet);
        }
        connection.sendQueue.clear();
    }
}
