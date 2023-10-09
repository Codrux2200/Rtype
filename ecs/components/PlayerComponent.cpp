/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"

ECS::PlayerComponent::PlayerComponent(int uid, const std::string& spritePath)
    : AComponent(uid), _spritePath(spritePath)
{
    _texture = sf::Texture();
    if (!_texture.loadFromFile(_spritePath))
        throw "TextureError";
    _sprite = std::make_unique<sf::Sprite>(_texture);
}

ECS::PlayerComponent::~PlayerComponent()
{
}

void ECS::PlayerComponent::setSprite(const std::string& newSpritePath)
{
    _spritePath = newSpritePath;
}

std::string ECS::PlayerComponent::getSprite() const
{
    return _spritePath;
}

void ECS::PlayerComponent::update(const std::vector<int> positions)
{
    sf::Vector2f spritePosition;

    if (_texture.loadFromFile(_spritePath)) {
        _sprite->setTexture(_texture);
        spritePosition.x = positions.at(0);
        spritePosition.y = positions.at(1);
        _sprite->setPosition(spritePosition);
    }
}

void ECS::PlayerComponent::draw(sf::RenderWindow &window)
{
    window.draw(*_sprite);
}