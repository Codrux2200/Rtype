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
#include "RotationComponent.hpp"
#include "ScaleComponent.hpp"
#include "SpriteComponent.hpp"

EnemyEntity::EnemyEntity() : Entity(0)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    addComponent(std::make_shared<ECS::PositionComponent>(600, 300));
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
    addComponent(std::make_shared<ECS::SpriteComponent>(enemyTexture, enemyRect));
    addComponent(std::make_shared<ECS::EnemyComponent>());
}

