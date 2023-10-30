/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

#include <utility>

ECS::SpriteComponent::SpriteComponent(sf::Texture texture, sf::Rect<int> rect) : _rect(rect), _texture(std::move(texture)), _sprite(_texture)
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

sf::Rect<int> &ECS::SpriteComponent::getRect()
{
    return _rect;
}

void ECS::SpriteComponent::setMaxIteration(sf::Vector2i max_iteration)
{
    _maxIterations = max_iteration;
}

void ECS::SpriteComponent::moveRect()
{
    _iterations.x++;
    if (_iterations.x >= _maxIterations.x) {
        _iterations.x = 0; _iterations.y++;
        if (_iterations.y >= _maxIterations.y) {
            _iterations.y = 0;
        }
    }
    _rect.left = _iterations.x * _rect.width;
    _rect.top = _iterations.y * _rect.height;
    _sprite.setTextureRect(_rect);
}
