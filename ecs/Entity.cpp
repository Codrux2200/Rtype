/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"

ECS::Entity::Entity(int id)
{
    _id = id;
    // components = std::vector<IComponent>();
    // _tags = std::vector<Tag>();
}

ECS::Entity::~Entity()
{
    // components.clear();
    // _tags.clear();
    // components.~vector<IComponent>();
    // _tags.~vector<Tag>();
}
