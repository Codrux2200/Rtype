/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBullet
*/

#include "PlayerBullet.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerBulletComponent.hpp"
#include "PositionComponent.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

ECS::PlayerBullet::PlayerBullet(int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    std::shared_ptr<sf::Texture> bulletTexture = std::make_shared<sf::Texture>();
    if (!bulletTexture->loadFromFile("assets/rickBullet.png")) {
        std::cerr << "Error loading player bullet texture" << std::endl;
        return;
    }

    sf::Rect<int> bulletRect;
    bulletRect.left = 0;
    bulletRect.top = 0;
    bulletRect.width = bulletTexture->getSize().x;
    bulletRect.height = bulletTexture->getSize().y;
    addComponent(
    std::make_shared<ECS::SpriteComponent>(bulletTexture, bulletRect));

    std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>();
    if (!soundComponent->addSound("bullet", "assets/sound/laser.ogg")) {
        std::cerr << "Error loading bullet sound" << std::endl;
        return;
    }
    if (!soundComponent->addSound("BossHit", "assets/sound/damage.ogg")) {
        std::cerr << "Error loading BossHit sound" << std::endl;
        return;
    }
    soundComponent->setToBePlayed("bullet", true);
    addComponent(soundComponent);
    addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));
    addComponent(std::make_shared<ECS::PlayerBulletComponent>());
    addComponent(std::make_shared<ECS::VelocityComponent>(0, 0));
    updateGameComponents();
}
