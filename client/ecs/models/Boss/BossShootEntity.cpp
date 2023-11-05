/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootEntity
*/

#include "BossShootEntity.hpp"
#include <iostream>
#include "BossShootComponent.hpp"
#include "PositionComponent.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

BossShootEntity::BossShootEntity(int id) : Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    std::shared_ptr<sf::Texture> bulletTexture = std::make_shared<sf::Texture>();
    if (!bulletTexture->loadFromFile("assets/boss/boss_bullet.png")) {
        std::cerr << "Error loading boss bullet texture" << std::endl;
        return;
    }

    sf::Rect<int> bulletRect;
    bulletRect.left = 0;
    bulletRect.top = 0;
    bulletRect.width = 500;
    bulletRect.height = 500;
    addComponent(
    std::make_shared<ECS::SpriteComponent>(bulletTexture, bulletRect, 9, 0.1f, sf::Vector2i(9, 1), true));

    addComponent(std::make_shared<ECS::ScaleComponent>(0.11f, 0.11f));
    addComponent(std::make_shared<ECS::BossShootComponent>());
    addComponent(std::make_shared<ECS::VelocityComponent>());
    updateGameComponents();
}