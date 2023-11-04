/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerEntity
*/

#include "PlayerEntity.hpp"
#include "PositionComponent.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "ScaleComponent.hpp"
#include "ShootComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"
#include "ConvertPath.hpp"

namespace ECS {
    PlayerEntity::PlayerEntity(int id) : Entity(id)
    {
        std::shared_ptr<ECS::SoundComponent> soundComponent = std::make_shared<ECS::SoundComponent>();

        if (!soundComponent->addSound("shoot", "assets/sound/laser.ogg")) {
            std::cerr << "Error loading shoot sound" << std::endl;
            return;
        }
        std::shared_ptr<sf::Texture> playerTexture = std::make_shared<sf::Texture>();

        if (!playerTexture->loadFromFile(ConvertPath::convertPath("assets/ship 1.png"))) {
            std::cerr << "Error loading player playerTexture" << std::endl;
            return;
        }

        sf::Rect<int> playerRect;

        playerRect.left = 0;
        playerRect.top = 0;
        playerRect.width = playerTexture->getSize().x / 2;
        playerRect.height = playerTexture->getSize().y;

        addComponent(soundComponent);
        addComponent(std::make_shared<ECS::SpriteComponent>(playerTexture, playerRect, 2, 0.1f, sf::Vector2i(2, 1), true));
        addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
        addComponent(std::make_shared<ECS::ScaleComponent>(0.16f, 0.16f));
        addComponent(std::make_shared<ECS::ShootComponent>());
        isEnabled = false;
    }
}
