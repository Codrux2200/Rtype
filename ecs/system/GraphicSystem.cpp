/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GraphicSystem
*/

#include "GraphicSystem.hpp"
#include "PlayerComponent.hpp"
#include <iostream>

ECS::GraphicSystem::GraphicSystem()
    : ASystem(ECS::SystemType::GRAPHIC), _modeSize(800, 600) ,_window(sf::VideoMode(sf::Vector2u(800,600), 32), "SFML Window")
{

}

ECS::GraphicSystem::~GraphicSystem()
{
}


void ECS::GraphicSystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime){
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
            }
        }

        // Clear the window
        _window.clear();

        // Draw stuff
        PlayerComponent *playerComponent = dynamic_cast<PlayerComponent *>(sceneManager.getScene(SceneType).entitiesList.at(1)->components.at(0));
        sf::Texture texture = sf::Texture();
        if (!texture.loadFromFile(playerComponent->getSprite()))
            std::cout << "error" << std::endl;
        // Display the contents of the window
        sf::Sprite sprite = sf::Sprite(texture);
        sprite.setTexture(texture);
        _window.draw(sprite);
        _window.display();
}

sf::RenderWindow &ECS::GraphicSystem::getWindow()
{
    return _window;
}