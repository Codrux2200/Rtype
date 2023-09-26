/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include "Core.hpp"

ECS::Core::Core()
{
    sceneManager = SceneManager();
}

ECS::Core::~Core()
{
    sceneManager.~SceneManager();
}

void ECS::Core::mainLoop()
{
    int arrow = 0;

    while(!sceneManager.shouldClose) {
        if (arrow == 10)
            sceneManager.shouldClose = true;
        arrow += 1;
        Scene firstScene = sceneManager.getScene(SceneType::MAIN_MENU);
        firstScene.entitiesList.insert(std::pair<int, Entity>(arrow, Entity(arrow)));
        sceneManager.getScene(SceneType::MAIN_MENU).loadEntity(arrow);
        sceneManager.getScene(SceneType::MAIN_MENU).unloadEntity(arrow);
    }
}
