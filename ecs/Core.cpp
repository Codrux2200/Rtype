/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include "Core.hpp"
#include "PlayerComponent.hpp"
#include "HealthComponent.hpp"

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
        Scene firstScene = sceneManager.getScene(ECS::SceneType::MAIN_MENU);
        // create the player entity if it doesn't exist
        if (firstScene.entitiesList.size() < 1) {
            // create a tag vector
            std::vector<Tag> tags;
            tags.push_back(ECS::Tag::MOVABLE);
            tags.push_back(ECS::Tag::DESTROYABLE);
            firstScene.entitiesList.insert(std::pair<int, Entity>(1, Entity(1, tags)));
            // create the player component
            firstScene.entitiesList[1].components.push_back(PlayerComponent(10));
            // create the health component
            firstScene.entitiesList[1].components.push_back(HealthComponent(11));
        } else {
            // update the health component
            firstScene.entitiesList[1].components[1].setHealth(100 - arrow * 10);
        }
        // close the window if the health is 0
        if (firstScene.entitiesList[1].components[1].getHealth() == 0)
            sceneManager.shouldClose = true;
        arrow++;
    }
}
