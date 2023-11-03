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
        sf::Texture playerTexture;

        if (!playerTexture.loadFromFile(ConvertPath::convertPath("assets/Ship6.png"))) {
            std::cerr << "Error loading player playerTexture" << std::endl;
            return;
        }

        sf::Rect<int> playerRect;

        playerRect.left = 0;
        playerRect.top = 0;
        playerRect.width = playerTexture.getSize().x;
        playerRect.height = playerTexture.getSize().y;

        addComponent(soundComponent);
        addComponent(std::make_shared<ECS::SpriteComponent>(playerTexture, playerRect));
        addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
        addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f));
        addComponent(std::make_shared<ECS::ShootComponent>());
        isEnabled = false;
    }
}
