/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"

ECS::EnemyComponent::EnemyComponent(int uid, const std::string &spritePath)
    : _spritePath(spritePath)
{
    _uid = uid;
    _texture = sf::Texture();
    if (!_texture.loadFromFile(_spritePath))
        throw "TextureError";
    _sprite = std::make_unique<sf::Sprite>(_texture);
}

ECS::EnemyComponent::~EnemyComponent()
{
}

void ECS::EnemyComponent::setSprite(const std::string &newSpritePath)
{
    _spritePath = newSpritePath;
}

std::string ECS::EnemyComponent::getSprite() const
{
    return _spritePath;
}

void ECS::EnemyComponent::update(const std::vector<int> positions)
{
    sf::Vector2f position(positions.at(0), positions.at(1));

    if (_texture.loadFromFile(_spritePath)) {
        _sprite->setTexture(_texture);
        _sprite->setPosition(position);        
    }
}

void ECS::EnemyComponent::draw(sf::RenderWindow &window)
{
    window.draw(*_sprite);
}