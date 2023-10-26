/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyEntity
*/

#include "EnemyEntity.hpp"
#include <iostream>
#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    EnemyEntity::EnemyEntity(int id) : Entity(id)
    {
        addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
        addComponent(std::make_shared<ECS::ScaleComponent>(0.03f, 0.03f));
        // addComponent(std::make_shared<ECS::RotationComponent>(270.0f));

        sf::Texture enemyTexture;
        if (!enemyTexture.loadFromFile("assets/Ship5.png")) {
            std::cout << "Error loading enemy texture" << std::endl;
            return;
        }

        sf::Rect<int> enemyRect;
        enemyRect.left = 0;
        enemyRect.top = 0;
        enemyRect.width = enemyTexture.getSize().x;
        enemyRect.height = enemyTexture.getSize().y;
        addComponent(
        std::make_shared<ECS::SpriteComponent>(enemyTexture, enemyRect));
        addComponent(std::make_shared<ECS::EnemyComponent>());

        std::shared_ptr<sf::SoundBuffer> soundbuffer = std::make_shared<sf::SoundBuffer>();
        if(!soundbuffer->loadFromFile("assets/sound/death.ogg")) {
            std::cerr << "Error loading sound" << std::endl;
            return;
        }
        std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>(*soundbuffer);
        std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>(sound, soundbuffer);
        soundComponent->startPlaying = false;
        addComponent(soundComponent);
    }

    EnemyEntity::~EnemyEntity()
    {
        std::cout << "Destroying enemy entity" << std::endl;
        std::shared_ptr<ECS::SoundComponent> soundComponent = getComponent<ECS::SoundComponent>();

        if (soundComponent == nullptr)
            return;

        soundComponent->play();
    }
}