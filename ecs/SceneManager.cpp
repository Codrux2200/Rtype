/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

ECS::SceneManager::SceneManager()
{
   // _scenes = std::map<SceneType, Scene>();
    _currentScene = SceneType::MAIN_MENU;
    _shouldClose = false;
}

ECS::SceneManager::~SceneManager()
{
    // _scenes.clear();
    // _scenes.~map<SceneType, Scene>();
}
