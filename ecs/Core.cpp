/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include "Core.hpp"

ECS::Core::Core()
{
    system = std::map<std::string, ISystem>();
    sceneManager = SceneManager();
}

ECS::Core::~Core()
{
    system.clear();
    system.~map<std::string, ISystem>();
    sceneManager.~SceneManager();
}
