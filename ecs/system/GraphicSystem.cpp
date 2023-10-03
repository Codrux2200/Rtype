/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GraphicSystem
*/

#include "GraphicSystem.hpp"

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

        // Display the contents of the window
        _window.display();
}