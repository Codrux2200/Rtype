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
        std::cout << "loop nb: " << arrow << " nb of entities: " << firstScene.entitiesList.size() << std::endl;
        // create the player entity if it doesn't exist
        if (firstScene.entitiesList.size() < 1) {
            // create a tag vector
            std::vector<Tag> tags;
            tags.push_back(ECS::Tag::MOVABLE);
            tags.push_back(ECS::Tag::DESTROYABLE);
            // add the player entity to the scene
            firstScene.entitiesList.insert(std::pair<int, Entity*>(1, new Entity(1, tags)));
            // create the player component
            firstScene.entitiesList.at(1)->components.push_back(PlayerComponent(10));
            // create the health component
            firstScene.entitiesList.at(1)->components.push_back(HealthComponent(11));
            std::cout << "nb of entities: " << firstScene.entitiesList.size() << std::endl;
        } else {
            HealthComponent health = static_cast<HealthComponent&>(firstScene.entitiesList.at(1)->components.at(1));
            std::cout << "health id: " << health.getUid() << std::endl;
            std::cout << "health value: " << health.getValue().size() << std::endl;
            for (int i = 0; i < health.getValue().size(); i++) {
                std::cout << "health value: " << health.getValue().at(i) << std::endl;
            }
        }
        arrow++;
    }   
}
