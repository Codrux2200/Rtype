/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

ECS::SceneManager::SceneManager()
{
    _currentScene = SceneType::MAIN_MENU;
    shouldClose = false;
}

ECS::SceneManager::~SceneManager()
{
}

ECS::Scene ECS::SceneManager::getScene(SceneType sceneType)
{
    return ECS::Scene(sceneType);
}
