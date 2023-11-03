/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

#include <utility>

ECS::SpriteComponent::SpriteComponent(std::shared_ptr<sf::Texture> texture, sf::Rect<int> rect, int maxIterations, float animSpeed, sf::Vector2i spriteGrid)
    : _rect(rect), _texture(std::move(texture)), _sprite(*_texture),
      maxIterations(maxIterations), animSpeed(animSpeed),
      spriteGrid(spriteGrid)
{
    _sprite.setTextureRect(_rect);
//    _sprite.setOrigin(sf::Vector2f(static_cast<float>(_rect.width) / 2, static_cast<float>(_rect.height) / 2));
}

ECS::SpriteComponent::~SpriteComponent()
{
}

void ECS::SpriteComponent::setTexture(std::shared_ptr<sf::Texture> &texture)
{
    _texture = texture;
    _sprite.setTexture(*_texture);
}

sf::Sprite ECS::SpriteComponent::getSprite() const
{
    return _sprite;
}

std::shared_ptr<ECS::IComponent> ECS::SpriteComponent::clone() const
{
    return std::make_shared<ECS::SpriteComponent>(_texture, _rect, maxIterations, animSpeed, spriteGrid);
}

sf::Rect<int> &ECS::SpriteComponent::getRect()
{
    return _rect;
}

void ECS::SpriteComponent::updateAnimation(float dt)
{
    if (!isAnimated)
        return;
    _timer += dt;
    if (_timer >= animSpeed) {
        _timer = 0;
        nextAnimation();
    }
}

void ECS::SpriteComponent::nextAnimation()
{
    animStep = (animStep + 1) % maxIterations;
    setAnimationStep(animStep);
}

void ECS::SpriteComponent::setAnimationStep(int step)
{
    animStep = step;
    _rect.left = step % spriteGrid.x * _rect.width;
    _rect.top = (step / spriteGrid.x) * _rect.height;
    _sprite.setTextureRect(_rect);
}
