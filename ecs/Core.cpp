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
}

void ECS::Core::mainLoop()
{
    int arrow = 0;

    sceneManager.setScene(ECS::SceneType::MAIN_MENU, Scene(ECS::SceneType::MAIN_MENU));
    while(!sceneManager.shouldClose) {
        if (arrow == 10)
            sceneManager.shouldClose = true;
        Scene &firstScene = sceneManager.getScene(ECS::SceneType::MAIN_MENU);
        std::cout << "Loop nb: " << arrow << " | Nb of entities: " << firstScene.entitiesList.size() << std::endl;
        // create the player entity if it doesn't exist
        if (firstScene.entitiesList.size() < 1) {
            // create a tag vector
            std::vector<Tag> tags;
            tags.push_back(ECS::Tag::MOVABLE);
            tags.push_back(ECS::Tag::DESTROYABLE);
            // add the player entity to the scene
            firstScene.entitiesList.emplace(1, new Entity(1, tags));
            // create the player component
            firstScene.entitiesList.at(1)->components.push_back(new PlayerComponent(10));
            // create the health component
            firstScene.entitiesList.at(1)->components.push_back(new HealthComponent(11));
            std::cout << "nb of entities: " << firstScene.entitiesList.size() << std::endl;
        } else {
            HealthComponent *health = dynamic_cast<HealthComponent *>(firstScene.entitiesList.at(1)->components.at(1));
            if (health != nullptr) {
                health->setValue(health->getValue().at(0) - 10, 0);
                if (health->getValue().at(0) <= 0) {
                    std::cout << "player is dead" << std::endl;
                    sceneManager.shouldClose = true;
                    continue;
                }
                std::cout << "player health: " << health->getValue().at(0) << std::endl;
            }
        }
        arrow++;
    }   
}
