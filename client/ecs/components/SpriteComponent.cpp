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

sf::Rect<int> ECS::SpriteComponent::getRect() const
{
    return _rect;
}

void ECS::SpriteComponent::setMaxIteration(sf::Vector2i max_iteration)
{
    _max_iteration = max_iteration;
}

void ECS::SpriteComponent::moveRect(void)
{
    if (_iterations.x == _max_iteration.x) {
        _iterations.x = 0;
        _rect.left -= _rect.width * (_max_iteration.x - 1);
        if (_iterations.y == _max_iteration.y) {
            _iterations.y = 0;
            _rect.top -= _rect.height * (_max_iteration.y - 1);
        } else {
            _rect.top += _rect.height;
            _iterations.y++;
        }
    } else {
        _rect.left += _rect.width;
        _iterations.x++;
    }
    _sprite.setTextureRect(_rect);
}
