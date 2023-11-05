/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Scene
*/

#include <iostream>
#include <algorithm>
#include "Scene.hpp"

ECS::Scene::Scene(SceneType sceneType) : _sceneType(sceneType)
{
}

ECS::Scene::~Scene()
{
}

int ECS::Scene::addEntity(std::shared_ptr<ECS::Entity> entity)
{
    if (!entity)
        return -1;
    std::cout << "Adding entity " << entity << std::endl;
    entitiesList.push_back(entity);
    return entity->getId();
}

void ECS::Scene::removeEntity(int entityID)
{
    for (int i = 0; i < (int) entitiesList.size(); i++) {
        if (entitiesList[i]->getId() == entityID) {
            entitiesList.erase(entitiesList.begin() + i);
            return;
        }
    }
}

ECS::SceneType ECS::Scene::getSceneType() const
{
    return _sceneType;
}

std::shared_ptr<ECS::Entity> ECS::Scene::getEntityByID(int entityID)
{
    auto it = std::find_if(entitiesList.begin(), entitiesList.end(),
    [entityID](const std::shared_ptr<Entity>& entity) {
        if (!entity)
            return false;
        return entity->getId() == entityID;
    });

    if (it != entitiesList.end())
        return *it;
    return nullptr;
}

int ECS::Scene::removeEntitiesToDestroy(float dt)
{
    std::cout << "Removing entities to destroy" << std::endl;
    if (entitiesList.size() <= 0)
        return _score;
    for (int i = (int) entitiesList.size() - 1; i >= 0; i--) {
        if (entitiesList[i] == nullptr)
            continue;
        if (entitiesList[i]->deathReason != Network::data::ALIVE) {
            if (entitiesList[i]->deathReason == Network::data::PLAYER_BULLET){
                _score += 10;
            }
            if (entitiesList[i]->onDestroy(dt)) {
                entitiesList.erase(entitiesList.begin() + i);
            }
        }
    }
    std::cout << "Removed entities to destroy" << std::endl;
    return _score;
}
