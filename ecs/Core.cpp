/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#include "Core.hpp"
#include "PlayerComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
#include "GraphicSystem.hpp"
#include "EventSystem.hpp"

ECS::Core::Core()
{
    sceneManager = SceneManager();
}

ECS::Core::~Core()
{
}

static void initPlayer(ECS::Scene &firstScene)
{
    std::vector<ECS::Tag> tags;
    tags.push_back(ECS::Tag::MOVABLE);
    tags.push_back(ECS::Tag::DESTROYABLE);

    if (firstScene.entitiesList.size() == 0) {
        // add the player entity to the scene
        firstScene.entitiesList.emplace(1, new ECS::Entity(1, tags));
        // create the player component
        firstScene.entitiesList.at(1)->components.push_back(new ECS::PlayerComponent(10, "assets/Ship6.png"));
        // create the health component
        firstScene.entitiesList.at(1)->components.push_back(new ECS::HealthComponent(11));
        // create the position component
        firstScene.entitiesList.at(1)->components.push_back(new ECS::PositionComponent(0, 0, 12));
        // change the player default health to 1
        ECS::HealthComponent *health = dynamic_cast<ECS::HealthComponent *>(firstScene.entitiesList.at(1)->components.at(1));
        health->setValue(1);
    }
}

void ECS::Core::mainLoop()
{
    int deltaTime = 0; 

    sceneManager.setScene(ECS::SceneType::MAIN_MENU, Scene(ECS::SceneType::MAIN_MENU));
    GraphicSystem *graphicSystem = new GraphicSystem();
    EventSystem *eventSystem = new EventSystem();
    while(!sceneManager.shouldClose) {
        if (deltaTime > 1000)
            deltaTime = 0;
        Scene &firstScene = sceneManager.getScene(ECS::SceneType::MAIN_MENU);
        initPlayer(firstScene);
        eventSystem->update(sceneManager, ECS::SceneType::MAIN_MENU, deltaTime);
        graphicSystem->update(sceneManager, ECS::SceneType::MAIN_MENU, deltaTime);
        // if the window is closed, the loop is stopped
        if (!graphicSystem->getWindow().isOpen())
            sceneManager.shouldClose = true;
        deltaTime++;
    }
}
