/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GraphicSystem
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicSystem.hpp"
#include "PlayerComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "RotationComponent.hpp"

ECS::GraphicSystem::GraphicSystem(sf::RenderWindow &window) : _window(window)
{
    // typeSystem = ECS::SystemType::GRAPHIC;
    initBackground();
}

ECS::GraphicSystem::~GraphicSystem()
{
}

void ECS::GraphicSystem::initBackground()
{
    backgroundComponent = ECS::BackgroundComponent();
}

void ECS::GraphicSystem::update(ECS::SceneManager &sceneManager, int deltaTime, std::vector<Network::Packet> &packetQueue, Network::PacketManager &pacektManager) {

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))) {
            _window.close();
            sceneManager.shouldClose = true;
        }
    }

    // Clear the window
    _window.clear();


    // Draw entities
    for (auto &entity : sceneManager.getCurrentScene()->entitiesList) {
        auto spriteComponent = entity->getComponent<ECS::SpriteComponent>();
        if (spriteComponent == nullptr || !spriteComponent->isEnabled())
            continue;

        auto positionComponent = entity->getComponent<ECS::PositionComponent>();
        auto scaleComponent = entity->getComponent<ECS::ScaleComponent>();
        auto rotationComponent = entity->getComponent<ECS::RotationComponent>();

        std::vector<int> pos;
        std::vector<float> scale;
        std::vector<int> rotation;

        if (positionComponent != nullptr && positionComponent->isEnabled())
            pos = positionComponent->getValue();
        else
            pos = {0, 0};

        if (scaleComponent != nullptr && scaleComponent->isEnabled())
            scale = scaleComponent->getFloatValue();
        else
            scale = {1, 1};

        if (rotationComponent != nullptr && rotationComponent->isEnabled())
            rotation = rotationComponent->getValue();
        else
            rotation = {0};

        sf::Sprite sprite = spriteComponent->getSprite();

        sprite.setPosition(sf::Vector2f(pos[0], pos[1]));
        sprite.setScale(sf::Vector2f(scale[0], scale[1]));
        sprite.setRotation(sf::Angle(sf::degrees(rotation[0])));
        _window.draw(sprite);
    }
    _window.display();
}
