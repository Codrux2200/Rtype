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
#include "ConvertPath.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

namespace ECS {
    EnemyEntity::EnemyEntity(int id, ECS::Entity::EntityType type) : Entity(id)
    {
        addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
        addComponent(std::make_shared<ECS::ScaleComponent>(0.03f, 0.03f));
        addComponent(std::make_shared<ECS::VelocityComponent>(0, 0));
        // addComponent(std::make_shared<ECS::RotationComponent>(270.0f));

        sf::Texture enemyTexture;
        std::string texturePath;
        switch (type) {
            case ECS::Entity::ENEMY_CLASSIC:
                texturePath = ConvertPath::convertPath("assets/Ship5.png");
                break;
            case ECS::Entity::ENEMY_VELOCE:
                texturePath = ConvertPath::convertPath("assets/Ship_veloce.png");
                break;
            default:
                texturePath = ConvertPath::convertPath("assets/Ship5.png");
                break;
        }

        if (!enemyTexture.loadFromFile(ConvertPath::convertPath(texturePath))) {
            std::cerr << "Error loading enemy texture" << std::endl;
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

        std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>();

        // TODO: Bon c'est pas vraiment une todo, mais il faudrait peut-être ajouter un path
        //  pour le son dans le switch case au dessus, si besoin
        if (!soundComponent->addSound("enemy_death", "assets/sound/death.ogg")) {
            std::cerr << "Error loading enemy death sound" << std::endl;
            return;
        }
        addComponent(soundComponent);
        updateGameComponents();
    }
}
