/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>

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
    entitiesList.insert(std::pair<int, Entity>(entityID, Entity(entityID)));
    std::cout << "loadEntity " << entityID << '\n';
}

void ECS::Scene::unloadEntity(int entityID)
{
    entitiesList.erase(entityID);
    std::cout << "unloadEntity " << entityID << '\n';
}