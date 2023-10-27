/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** EventSystem
*/

#include "EventSystem.hpp"
#include "ControlComponent.hpp"

ECS::EventSystem::EventSystem(sf::RenderWindow &window) : _window(window)
{
}

ECS::EventSystem::~EventSystem()
{
}

void ECS::EventSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))) {
            _window.close();
            sceneManager.shouldClose = true;
        }
    }

    auto &actualScene = sceneManager.getCurrentScene();

    std::cout << "EventSystem" << std::endl;

    for (auto entity : actualScene->entitiesList) {
        if (entity == nullptr || !entity->isEnabled)
            continue;
        std::vector<std::shared_ptr<ECS::AEventComponent>> eventComponent = entity->getComponents<ECS::AEventComponent>();

        for (auto component : eventComponent) {
            if (component != nullptr)
                component->execute(packetQueue, *entity, deltaTime);
        }
    }

    std::cout << "EventSystem end" << std::endl;
}
