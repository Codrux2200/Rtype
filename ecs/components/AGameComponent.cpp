/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AGameComponent
*/

#include "AGameComponent.hpp"

namespace ECS {

    SceneType AGameComponent::getSceneChange()
    {
        return SceneType::GAME;
    }
}