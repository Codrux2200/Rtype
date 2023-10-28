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
        return entity->getId() == entityID;
    });

    if (it != entitiesList.end())
        return *it;
    return nullptr;
}

void ECS::Scene::removeEntitiesToDestroy()
{
    for (int i = 0; i < (int) entitiesList.size(); i++) {
        if (entitiesList[i]->deathReason != Network::data::ALIVE) {
            if (entitiesList[i]->onDestroy()) {
                entitiesList.erase(entitiesList.begin() + i);
                i--;
            }
        }
    }
}
