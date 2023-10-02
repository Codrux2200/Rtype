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
            // update the health component casted to HealthComponent
            //HealthComponent &health = dynamic_cast<HealthComponent &>(firstScene.entitiesList.at(1)->components[1]);
            //health.setHealth(health.getHealth() - arrow * 10);
        }
        std::cout << "nb of entities: " << firstScene.entitiesList.size() << std::endl;
        //close the window if the health is 0
        //HealthComponent *health = dynamic_cast<HealthComponent *>(&firstScene.entitiesList.at(1)->components[1]);
        //if (health == nullptr)
        //    sceneManager.shouldClose = true;
        //else if (health->getHealth() <= 0) {
        //    sceneManager.shouldClose = true;
        //    health->~HealthComponent();
        //}
        arrow++;
    }   
}
