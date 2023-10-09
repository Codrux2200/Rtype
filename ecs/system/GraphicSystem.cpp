/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GraphicSystem
*/

#include "GraphicSystem.hpp"
#include "PlayerComponent.hpp"
#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"

ECS::GraphicSystem::GraphicSystem()
    : _modeSize(800, 600) ,_window(sf::VideoMode(sf::Vector2u(800,600), 32), "SFML Window")
{
    typeSystem = ECS::SystemType::GRAPHIC;
    initBackground();
    _window.setFramerateLimit(60);
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                _window.close();
        }

        // Clear the window
        _window.clear();

        // Update the BackgroundComponent
        backgroundComponent.update(deltaTime, screenSize);

        // Draw the BackgroundComponent
        backgroundComponent.draw(_window);

        // Draw player
        PlayerComponent *playerComponent = dynamic_cast<PlayerComponent *>(sceneManager.getScene(SceneType).entitiesList.at(1)->components.at(0));
        PositionComponent *positionComponent = dynamic_cast<PositionComponent *>(sceneManager.getScene(SceneType).entitiesList.at(1)->components.at(2));
        playerComponent->update(positionComponent->getValue());
        playerComponent->draw(_window);

        // Draw enemies
        for (auto &entity : sceneManager.getScene(SceneType).entitiesList) {
            if (entity.first != 1) {
                EnemyComponent *enemyComponent = dynamic_cast<EnemyComponent *>(entity.second->components.at(0));
                PositionComponent *positionComponent = dynamic_cast<PositionComponent *>(entity.second->components.at(2));
                enemyComponent->update(positionComponent->getValue());
                enemyComponent->draw(_window);
            }
        }
        _window.display();
}

sf::RenderWindow &ECS::GraphicSystem::getWindow()
{
    return _window;
}