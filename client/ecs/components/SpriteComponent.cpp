/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

ECS::SpriteComponent::SpriteComponent(sf::Texture texture, sf::Rect<int> rect) : _rect(rect), _texture(texture), _sprite(_texture)
{
    _sprite.setTextureRect(_rect);
}

ECS::SpriteComponent::~SpriteComponent()
{
}

void ECS::SpriteComponent::setTexture(sf::Texture &texture)
{
    _sprite.setTexture(texture);
}

const sf::Sprite &ECS::SpriteComponent::getSprite() const
{
    return _sprite;
}

std::shared_ptr<ECS::IComponent> ECS::SpriteComponent::clone() const
{
    return std::make_shared<ECS::SpriteComponent>(_texture, _rect);
}
