/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GameSystem
*/

#include "GameSystem.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
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

    for (auto &entity : actualScene->entitiesList) {
        if (!entity->isEnabled)
            continue;
        std::vector<std::shared_ptr<ECS::AGameComponent>> eventComponent = entity->getComponents<ECS::AGameComponent>();

        for (auto &component : eventComponent) {
            if (component != nullptr)
                component->update(packetQueue, *entity, deltaTime);
        }
    }
}
