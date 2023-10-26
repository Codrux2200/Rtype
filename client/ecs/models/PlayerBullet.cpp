/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBullet
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteComponent.hpp"
#include "PlayerBullet.hpp"
#include "PositionComponent.hpp"
#include "SoundComponent.hpp"

ECS::PlayerBullet::PlayerBullet(int id) : ECS::Entity(id)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("assets/rickBullet.png")) {
        std::cout << "Error loading enemy texture" << std::endl;
        return;
    }

    sf::Rect<int> bulletRect;
    bulletRect.left = 0;
    bulletRect.top = 0;
    bulletRect.width = bulletTexture.getSize().x;
    bulletRect.height = bulletTexture.getSize().y;
    addComponent(
    std::make_shared<ECS::SpriteComponent>(bulletTexture, bulletRect));

    std::shared_ptr<sf::SoundBuffer> soundbuffer = std::make_shared<sf::SoundBuffer>();
    if (!soundbuffer->loadFromFile("assets/sound/laser.ogg")) {
        std::cerr << "Error loading sound" << std::endl;
        return;
    }
    std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>(*soundbuffer);
    addComponent(std::make_shared<ECS::SoundComponent>(sound, soundbuffer));
}
