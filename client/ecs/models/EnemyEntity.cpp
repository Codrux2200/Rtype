/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyEntity
*/

#include "EnemyEntity.hpp"
#include <iostream>
#include "ConvertPath.hpp"
#include "EnemyComponent.hpp"
#include "EnemyDeathComponent.hpp"
#include "PositionComponent.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

namespace ECS {
    EnemyEntity::EnemyEntity(int id, ECS::Entity::EntityType type) : Entity(id)
    {
        std::shared_ptr<sf::Texture> enemyTexture = std::make_shared<sf::Texture>();
        std::string texturePath;

        float scale = 0.8f;

        switch (type) {
            case ECS::Entity::ENEMY_CLASSIC:
                texturePath = "assets/enemy2.png";
                break;
            case ECS::Entity::ENEMY_VELOCE:
                texturePath = "assets/enemy1.png";
                scale = 1;
                break;
            default:
                texturePath = "assets/enemy2.png";
                break;
        }

        if (!enemyTexture->loadFromFile(ConvertPath::convertPath(texturePath))) {
            std::cerr << "Error loading enemy texture" << std::endl;
            return;
        } else {
            std::cerr << "Enemy texture loaded" << std::endl;
        }

        sf::Rect<int> enemyRect;
        enemyRect.left = 0;
        enemyRect.top = 0;
        enemyRect.width = enemyTexture->getSize().x / 4;
        enemyRect.height = enemyTexture->getSize().y;

        std::cout << "Enemy rect: " << enemyRect.width << " " << enemyRect.height << std::endl;
        addComponent(
        std::make_shared<ECS::SpriteComponent>(enemyTexture, enemyRect, 4, 0.2f, sf::Vector2i(4, 1), true));
        addComponent(std::make_shared<ECS::EnemyDeathComponent>());
        addComponent(std::make_shared<ECS::EnemyComponent>(nullptr, type));

        std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>();

        addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
//        addComponent(std::make_shared<ECS::ScaleComponent>(0.03f, 0.03f));
        addComponent(std::make_shared<ECS::VelocityComponent>(0, 0));
        addComponent(std::make_shared<ECS::ScaleComponent>(scale, scale));
        if (!soundComponent->addSound("enemy_death", "assets/sound/death.ogg")) {
            std::cerr << "Error loading enemy death sound" << std::endl;
            return;
        }
        addComponent(soundComponent);
        updateGameComponents();
    }
}
