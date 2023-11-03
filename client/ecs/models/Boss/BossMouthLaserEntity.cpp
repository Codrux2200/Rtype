/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserMouthEntity
*/

#include "BossMouthLaserEntity.hpp"
#include <iostream>
#include "BossLaserMouthComponent.hpp"
#include "ConvertPath.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

BossMouthLaserEntity::BossMouthLaserEntity(int id) : ECS::Entity(id)
{
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

    if (!texture->loadFromFile(ConvertPath::convertPath("assets/boss/laser spritesheet.png"))) {
        std::cerr << "Error loading boss laser texture" << std::endl;
        return;
    }

    sf::Rect<int> rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = texture->getSize().x / 3;
    rect.height = texture->getSize().y;

    auto sprite = std::make_shared<ECS::SpriteComponent>(texture, rect, 1, 0, sf::Vector2i(3, 1));
    sprite->setAnimationStep(2);
    addComponent(sprite);
    addComponent(std::make_shared<ECS::PositionComponent>());
    addComponent(std::make_shared<ECS::VelocityComponent>());
    addComponent(std::make_shared<ECS::BossLaserMouthComponent>());
    updateGameComponents();
}