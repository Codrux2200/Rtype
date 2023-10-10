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
    std::map<SceneType, std::shared_ptr<Scene>> scenes;

    scenes.insert(std::pair<SceneType, std::shared_ptr<Scene>>(SceneType::MAIN_MENU, _initMainMenuScene()));
    sceneManager = SceneManager(scenes);
    _systems.push_back(std::make_unique<GraphicSystem>());
    _systems.push_back(std::make_unique<EventSystem>());
}

std::shared_ptr<ECS::Scene> ECS::Core::_initMainMenuScene()
{
    std::shared_ptr<ECS::Scene> scene = std::make_shared<ECS::Scene>(ECS::SceneType::MAIN_MENU);

    // std::shared_ptr<ECS::Entity> entity = std::make_shared<ECS::Entity>(0);
    // entity->addComponent(std::make_shared<ECS::PlayerComponent>(0));
    // entity->addComponent(std::make_shared<ECS::HealthComponent>(100));
    // entity->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    // scene->addEntity(entity);
    return scene;
}

void ECS::Core::mainLoop(RType::Connection &connection)
{
    int deltaTime = 0;

    // sceneManager.setScene(ECS::SceneType::MAIN_MENU, Scene(ECS::SceneType::MAIN_MENU));
    // GraphicSystem *graphicSystem = new GraphicSystem();
    // EventSystem *eventSystem = new EventSystem();

    // while(!sceneManager.shouldClose) {
    //     if (deltaTime > 1000)
    //         deltaTime = 0;

    //     // if the window is closed, the loop is stopped
    //     if (!graphicSystem->getWindow().isOpen())
    //         sceneManager.shouldClose = true;
    //     deltaTime++;
    // }
}
