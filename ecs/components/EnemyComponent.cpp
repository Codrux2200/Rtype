/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"

ECS::EnemyComponent::EnemyComponent()
{
}

ECS::EnemyComponent::~EnemyComponent()
{
}

void ECS::EnemyComponent::setValue(std::vector<int> values)
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