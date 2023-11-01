/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossShootEntity
*/

#include "BossShootEntity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BossShootComponent.hpp"
#include "PositionComponent.hpp"
#include "SFML/Audio.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

BossShootEntity::BossShootEntity(int id) : Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("assets/boss/boss_bullet.png")) {
        std::cout << "Error loading enemy texture" << std::endl;
        return;
    }

    sf::Rect<int> bulletRect;
    bulletRect.left = 0;
    bulletRect.top = 0;
    bulletRect.width = 500;
    bulletRect.height = 500;
    addComponent(
    std::make_shared<ECS::SpriteComponent>(bulletTexture, bulletRect));

    addComponent(std::make_shared<ECS::ScaleComponent>(0.1f, 0.1f));
    addComponent(std::make_shared<ECS::BossShootComponent>());
    addComponent(std::make_shared<ECS::VelocityComponent>());
    updateGameComponents();
}