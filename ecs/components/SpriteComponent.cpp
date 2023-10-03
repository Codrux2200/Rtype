/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

ECS::SpriteComponent::SpriteComponent()
    : AComponent()
{
}

ECS::SpriteComponent::~SpriteComponent()
{
}

void ECS::SpriteComponent::setTexture(sf::Texture texture)
{
    _sprite.setTexture(texture);
}

const sf::Sprite &ECS::SpriteComponent::getSprite() const
{
    return _sprite;
}