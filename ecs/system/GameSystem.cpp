/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GameSystem
*/

#include <iostream>
#include "GameSystem.hpp"
#include "AGameComponent.hpp"

ECS::GameSystem::GameSystem()
{
    // typeSystem = ECS::SystemType::GAME;
}

ECS::GameSystem::~GameSystem()
{
}

void ECS::GameSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    auto &actualScene = sceneManager.getCurrentScene();

    std::cout << "GameSystem" << std::endl;

    for (auto entity : actualScene->entitiesList) {
        if (entity == nullptr || !entity->isEnabled)
            continue;
        std::vector<std::shared_ptr<ECS::AGameComponent>> gameComponents = entity->getComponents<ECS::AGameComponent>();

        for (auto component : gameComponents) {
            if (component != nullptr)
                component->update(packetQueue, *entity, deltaTime);
        }
    }
    std::cout << "GameSystem end" << std::endl;
}
