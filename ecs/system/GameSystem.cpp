/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GameSystem
*/

#include "GameSystem.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"

ECS::GameSystem::GameSystem()
{
    typeSystem = ECS::SystemType::GAME;
}

ECS::GameSystem::~GameSystem()
{
}

void ECS::GameSystem::update(
    SceneManager &sceneManager, const SceneType &SceneType, const float &deltaTime)
{
    ECS::Scene &scene = sceneManager.getScene(SceneType);

    // unload entities with no health
    for (auto &entity : scene.entitiesList) {
        if (entity.first != 1) {
            ECS::HealthComponent *healthComponent = dynamic_cast<ECS::HealthComponent *>(entity.second->components.at(1));
            ECS::PositionComponent *positionComponent = dynamic_cast<ECS::PositionComponent *>(entity.second->components.at(2));
            if (healthComponent->getValue().at(0) <= 0)
                scene.unloadEntity(entity.first);
            if (positionComponent->getValue().at(0) <= -128)
                scene.unloadEntity(entity.first);
        }
    }
    // update all enemies with a movement event
    for (auto &entity : scene.entitiesList) {
        if (entity.first != 1) {
            _moveEnemy(entity.second);
        }
    }
}

void ECS::GameSystem::_moveEnemy(ECS::Entity *enemy)
{
    std::vector<int> position;

    ECS::PositionComponent *positionComponent = dynamic_cast<ECS::PositionComponent *>(enemy->components.at(2));
    position = positionComponent->getValue();
    positionComponent->setValue(position.at(0) - 1, position.at(1));
}