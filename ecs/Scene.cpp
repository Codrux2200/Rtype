/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Scene
*/

#include "Scene.hpp"

ECS::Scene::Scene(SceneType sceneType)
{
    sceneType = sceneType;
    entitiesList = std::map<int, Entity>();
}

ECS::Scene::~Scene()
{
    entitiesList.clear();
    entitiesList.~map<int, Entity>();
}

void ECS::Scene::loadEntity(int entityID)
{
    entitiesList[entityID] = Entity(entityID);
}

void ECS::Scene::unloadEntity(int entityID)
{
    entitiesList.erase(entityID);
}