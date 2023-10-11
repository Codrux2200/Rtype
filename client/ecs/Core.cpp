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

ECS::Core::Core()
{
    std::map<SceneType, std::shared_ptr<Scene>> scenes;

    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::MAIN_MENU, _initMainMenuScene()));
    sceneManager = SceneManager(scenes);
    _systems.push_back(std::make_unique<GraphicSystem>());
    _systems.push_back(std::make_unique<EventSystem>());

    _initEntities();

    scenes.at(SceneType::MAIN_MENU)->addEntity(_entityFactory.createEntity("button", 4));
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

    button->addComponent(std::make_shared<ECS::SpriteComponent>(texture, rect));
    button->addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));
    _entityFactory.registerEntity(button, "button");
}

std::shared_ptr<ECS::Scene> ECS::Core::_initMainMenuScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(ECS::SceneType::MAIN_MENU);

    return scene;
}

void ECS::Core::mainLoop(RType::Connection &connection)
{
    int deltaTime = 0;

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
