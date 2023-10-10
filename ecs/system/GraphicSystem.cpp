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
    : _modeSize(800, 600) ,_window(sf::VideoMode(sf::Vector2u(800,600), 32), "SFML Window"), backgroundComponent("assets/background/6Background.png")
{
    typeSystem = ECS::SystemType::GRAPHIC;
    initBackground();
}

ECS::GraphicSystem::~GraphicSystem()
{
}

void ECS::GraphicSystem::initBackground()
{
    backgroundComponent = ECS::BackgroundComponent("assets/background/6Background.png");
}


void ECS::GraphicSystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime){
        sf::Vector2u screenSize = _window.getSize();

        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                _window.close();
        }

        // Clear the window
        _window.clear();

        // Update the BackgroundComponent
        backgroundComponent.update(deltaTime);

        // Draw the BackgroundComponent
        backgroundComponent.draw(_window);

        // Draw stuff
        for (int i = 1; i < sceneManager.getScene(SceneType).entitiesList.size() + 1 ; i ++ ){
            PlayerComponent *playerComponent = dynamic_cast<PlayerComponent *>(sceneManager.getScene(SceneType).entitiesList.at(i)->components["Player"]);
            PositionComponent *positionComponent = dynamic_cast<PositionComponent *>(sceneManager.getScene(SceneType).entitiesList.at(i)->components["Position"]);
            playerComponent->update(positionComponent->getValue());
            playerComponent->draw(_window);
        }
        _window.display();
}

sf::RenderWindow &ECS::GraphicSystem::getWindow()
{
    return _window;
}