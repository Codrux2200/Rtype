/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

ECS::SceneManager::SceneManager(std::map<SceneType, std::shared_ptr<Scene>> scenes) : _scenes(scenes)
{
    _currentScene = SceneType::MAIN_MENU;
    shouldClose = false;
}

ECS::SceneManager::~SceneManager()
{
}

std::shared_ptr<ECS::Scene> &ECS::SceneManager::getScene()
{
    return _scenes.at(_currentScene);
}

void ECS::SceneManager::setCurrentScene(SceneType sceneType)
{
    _currentScene = sceneType;
}
