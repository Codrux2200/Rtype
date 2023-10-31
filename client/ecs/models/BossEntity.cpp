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
#include "SFML/Audio/SoundBuffer.hpp"
#include "ScaleComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

BossEntity::BossEntity(int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>());
    addComponent(std::make_shared<ECS::ScaleComponent>(0.9f, 0.9f));

    sf::Texture bossTexture;
    if (!bossTexture.loadFromFile(ConvertPath::convertPath("assets/boss.png"))) {
        std::cerr << "Error loading enemy texture" << std::endl;
        return;
    }

    sf::Rect<int> bossRect;
    bossRect.left = 0;
    bossRect.top = 0;
    bossRect.width = 400;
    bossRect.height = 400;
    addComponent(
    std::make_shared<ECS::SpriteComponent>(bossTexture, bossRect));
    addComponent(std::make_shared<ECS::BossComponent>());

    std::shared_ptr<sf::SoundBuffer> soundBuffer = std::make_shared<sf::SoundBuffer>();
    if (!soundBuffer->loadFromFile(ConvertPath::convertPath("assets/sound/boss_death.ogg"))) {
        std::cerr << "Error loading sound" << std::endl;
        return;
    }
    std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>(*soundBuffer);
    std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>(sound, soundBuffer);
    soundComponent->startPlaying = false;
    addComponent(soundComponent);
    updateGameComponents();
}
