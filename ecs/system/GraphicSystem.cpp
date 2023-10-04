/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GraphicSystem
*/

#include "GraphicSystem.hpp"
#include "PlayerComponent.hpp"
#include "PositionComponent.hpp"
#include <iostream>

ECS::GraphicSystem::GraphicSystem()
    : ASystem(ECS::SystemType::GRAPHIC), _modeSize(800, 600) ,_window(sf::VideoMode(sf::Vector2u(800,600), 32), "SFML Window")
{
        initBackground();
}

ECS::GraphicSystem::~GraphicSystem()
{
}

void ECS::GraphicSystem::initBackground()
{
    backgroundComponent = ECS::BackgroundComponent();
}


void ECS::GraphicSystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime){
        sf::Vector2u screenSize = _window.getSize();

        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
            }
        }

        // Clear the window
        _window.clear();

        // Update the BackgroundComponent
        backgroundComponent.update(deltaTime, screenSize);

        // Draw the BackgroundComponent
        backgroundComponent.draw(_window);

        // Draw stuff
        PlayerComponent *playerComponent = dynamic_cast<PlayerComponent *>(sceneManager.getScene(SceneType).entitiesList.at(1)->components.at(0));
        PositionComponent *positionComponent = dynamic_cast<PositionComponent *>(sceneManager.getScene(SceneType).entitiesList.at(1)->components.at(2));
        playerComponent->update(positionComponent->getValue());
        playerComponent->draw(_window);
        _window.display();
}

sf::RenderWindow &ECS::GraphicSystem::getWindow()
{
    return _window;
}