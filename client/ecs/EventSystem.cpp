/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** EventSystem
*/

#include "EventSystem.hpp"
#include "PlayerComponent.hpp"
#include "ClickComponent.hpp"

ECS::EventSystem::EventSystem(sf::RenderWindow &window) : _window(window)
{
}

ECS::EventSystem::~EventSystem()
{
}

void ECS::EventSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    auto &actualScene = sceneManager.getCurrentScene();

    for (auto &entity : actualScene->entitiesList) {
        if (!entity->isEnabled)
            continue;
        auto eventComponent = entity->getComponent<ECS::EventComponent>();

        if (eventComponent) {
            eventComponent->execute( packetQueue, *entity, deltaTime);
        }
    }
}
