/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossEyesLaserEntity
*/

#include <iostream>
#include "BossEyesLaserEntity.hpp"
#include "PositionComponent.hpp"
#include "ScaleComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

BossEyesLaserEntity::BossEyesLaserEntity(int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>());
    addComponent(std::make_shared<ECS::ScaleComponent>(0.9f, 0.9f));
    addComponent(std::make_shared<ECS::VelocityComponent>());

    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile("assets/boss/laser_eyes.png")) {
        std::cerr << "Error loading boss laser texture" << std::endl;
        return;
    }

    sf::Rect<int> rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = texture->getSize().x;
    rect.height = texture->getSize().y;

    addComponent(std::make_shared<ECS::SpriteComponent>(texture, rect));
    updateGameComponents();
}