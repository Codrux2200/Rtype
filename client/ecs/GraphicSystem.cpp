/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** GraphicSystem
*/

#include <SFML/Graphics.hpp>
#include "GraphicSystem.hpp"
#include "ControlComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "RotationComponent.hpp"
#include "TextComponent.hpp"

ECS::GraphicSystem::GraphicSystem(sf::RenderWindow &window) : _window(window), backgroundComponent(window.getSize().x, window.getSize().y)
{
}

void ECS::GraphicSystem::update(ECS::SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) {
    // Clear the window
    _window.clear();

    // Draw background
    if (sceneManager.getCurrentScene()->getSceneType() == ECS::SceneType::GAME) {    
        sf::Vector2i screenSize = static_cast<sf::Vector2i>(_window.getSize());
        backgroundComponent.update(deltaTime, screenSize);
        backgroundComponent.draw(_window);
    }

    // Draw entities
    for (auto &entity : sceneManager.getCurrentScene()->entitiesList) {
        if (entity == nullptr || !entity->isEnabled)
            continue;
        auto TextComponent = entity->getComponent<ECS::TextComponent>();
        if (TextComponent != nullptr) {
            sf::Text Text = TextComponent->getText(); 
            _window.draw(Text);
        }
        auto spriteComponent = entity->getComponent<ECS::SpriteComponent>();
        if (spriteComponent == nullptr || !spriteComponent->isEnabled)
            continue;

        spriteComponent->updateAnimation(deltaTime);
        auto positionComponent = entity->getComponent<ECS::PositionComponent>();
        auto scaleComponent = entity->getComponent<ECS::ScaleComponent>();
        auto rotationComponent = entity->getComponent<ECS::RotationComponent>();

        std::vector<int> pos;
        std::vector<float> scale;
        std::vector<float> rotation;

        if (positionComponent != nullptr && positionComponent->isEnabled) {
            pos = positionComponent->getValue();
        }
        else
            pos = {0, 0};

        if (scaleComponent != nullptr && scaleComponent->isEnabled)
            scale = scaleComponent->getFloatValue();
        else
            scale = {1, 1};

        if (rotationComponent != nullptr && rotationComponent->isEnabled)
            rotation = rotationComponent->getFloatValue();
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
