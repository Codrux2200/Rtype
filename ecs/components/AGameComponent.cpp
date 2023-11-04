/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AGameComponent
*/

#include "AGameComponent.hpp"
#include "Scene.hpp"

namespace ECS {

    SceneType AGameComponent::getSceneChange()
    {
        return SceneType::GAME;
    }
}