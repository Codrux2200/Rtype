/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GameSystem
*/

#include "GameSystem.hpp"
#include "AGameComponent.hpp"

void ECS::GameSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    auto &actualScene = sceneManager.getCurrentScene();

    if (actualScene == nullptr)
        return;

    for (const auto& entity : actualScene->entitiesList) {
        if (entity == nullptr || !entity->isEnabled)
            continue;

        for (const auto& component : entity->gameComponents) {
            if (component != nullptr)
                component->update(packetQueue, *entity, deltaTime);
        }
    }
}
