/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"
#include <iostream>

ECS::Entity::Entity(int id, std::vector<Tag> tags)
{
    _id = id;
    components = std::vector<AComponent>();
    _tags = tags;
    std::cout << "Entity created with id " << id << '\n';
}

ECS::Entity::~Entity()
{
    components.clear();
    _tags.clear();
    components.~vector<AComponent>();
    _tags.~vector<Tag>();
}
