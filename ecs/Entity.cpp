/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"

ECS::Entity::Entity(int id, std::vector<Tag> tags)
{
    _id = id;
    components = std::vector<AComponent *>();
    _tags = tags;
}

ECS::Entity::~Entity()
{
    components.clear();
    _tags.clear();
}
