/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ButtonEntity
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ButtonEntity.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "MusicsComponent.hpp"

ECS::ButtonEntity::ButtonEntity(std::string &path, int x, int y) : Entity(0)
{
    addComponent(std::make_shared<ECS::PositionComponent>(x, y));

    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading button texture" << std::endl;
        return;
    }

    sf::Rect<int> rect;
    rect.left = 0;
    rect.top = 0;
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y;




    addComponent(std::make_shared<ECS::SpriteComponent>(texture, rect));
    addComponent(std::make_shared<ECS::ScaleComponent>(1.0, 1.0));

}
