/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>

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
    for (auto &entity : entitiesList) {
        if (entity->getId() == entityID)
            return entity;
    }
    return nullptr;
}
