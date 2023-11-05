/*
** StaticBackgroundEntity.cpp for client in /home/saad/Rtype/client/ecs/models
**
** Made by Saad Berrada
** Login   <saad.berrada@epitech.eu>
**
** Started on  Tue Oct 31 16:47:21 2023 Saad Berrada
** Last update Tue Oct 31 16:47:21 2023 Saad Berrada
*/

#include "StaticBackgroundEntity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "ScaleComponent.hpp"
#include "MusicsComponent.hpp"

ECS::StaticBackgroundEntity::StaticBackgroundEntity(std::string path) : Entity(0)
{
    addComponent(std::make_shared<ECS::PositionComponent>(0, 0));

    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path)) {
        std::cerr << "Error loading button texture" << std::endl;
        return;
    }

    sf::Rect<int> rect;
    rect.left = 0;
    rect.top = 0;
    rect.width = texture->getSize().x;
    rect.height = texture->getSize().y;

    addComponent(std::make_shared<ECS::SpriteComponent>(texture, rect));
}

ECS::StaticBackgroundEntity::~StaticBackgroundEntity()
{
}

