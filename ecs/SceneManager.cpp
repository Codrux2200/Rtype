/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

#include <utility>

ECS::SceneManager::SceneManager(std::map<SceneType, std::shared_ptr<Scene>> scenes) : _scenes(std::move(scenes))
{
    _currentScene = SceneType::MAIN_MENU;
    shouldClose = false;
}

ECS::SceneManager::~SceneManager()
{
}

std::shared_ptr<ECS::Scene> &ECS::SceneManager::getScene(ECS::SceneType sceneType)
{
    return _scenes.at(sceneType);
}

std::shared_ptr<ECS::Scene> &ECS::SceneManager::getCurrentScene()
{
    return _scenes.at(_currentScene);
}

void ECS::SceneManager::setCurrentScene(SceneType sceneType)
{
    _currentScene = sceneType;
}

void ECS::SceneManager::setScene(SceneType sceneType, Scene scene)
{
    _scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(sceneType, std::make_shared<Scene>(scene)));
}

ECS::SceneType ECS::SceneManager::getSceneType()
{
    return _currentScene;
}

std::map<ECS::SceneType, std::shared_ptr<ECS::Scene>> &ECS::SceneManager::getScenes()
{
    return _scenes;
}
