/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include "Core.hpp"
#include "PlayerComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
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
}

void ECS::Core::_initEntities()
{
    // Create player
    std::shared_ptr<ECS::Entity> p1 = std::make_shared<ECS::Entity>(0);
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

    button->addComponent(std::make_shared<ECS::ClickComponent>(rect, std::bind(&ECS::Core::_startGameCallback, this, std::placeholders::_1, std::placeholders::_2)));

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
        }
        scene->addEntity(player);
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
