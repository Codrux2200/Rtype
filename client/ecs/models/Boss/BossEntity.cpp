/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossEntity
*/

#include "BossEntity.hpp"
#include "BossComponent.hpp"
#include "ConvertPath.hpp"
#include "PositionComponent.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

BossEntity::BossEntity(int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>());
    addComponent(std::make_shared<ECS::ScaleComponent>(0.9f, 0.9f));
    addComponent(std::make_shared<ECS::VelocityComponent>(0, 0));

    std::shared_ptr<sf::Texture> bossTexture = std::make_shared<sf::Texture>();
    if (!bossTexture->loadFromFile(ConvertPath::convertPath("assets/boss/boss2.png"))) {
        std::cerr << "Error loading enemy texture" << std::endl;
        return;
    }

    sf::Rect<int> bossRect;
    bossRect.left = 0;
    bossRect.top = 0;
    bossRect.width = 400;
    bossRect.height = 400;
    addComponent(
    std::make_shared<ECS::SpriteComponent>(bossTexture, bossRect, 1, 1, sf::Vector2i(5, 1)));
    addComponent(std::make_shared<ECS::BossComponent>());

    std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>();
    if (!soundComponent->addSound("boss_death", "assets/sound/boss_death.ogg")) {
        std::cerr << "Error loading boss death sound" << std::endl;
        return;
    }
    if (!soundComponent->addSound("boss_eyes_atk", "assets/sound/Buzz.ogg")) {
        std::cerr << "Error loading boss eyes sound" << std::endl;
        return;
    }
    if (!soundComponent->addSound("boss_mouth_atk", "assets/sound/mouth_throwing.ogg")) {
        std::cerr << "Error loading boss mouth sound" << std::endl;
        return;
    }
    if (!soundComponent->addSound("boss_shoot", "assets/sound/laser.ogg")) {
        std::cerr << "Error loading boss shoot sound" << std::endl;
        return;
    }
    addComponent(soundComponent);
    updateGameComponents();
}
