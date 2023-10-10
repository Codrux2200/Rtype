/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"
#include "BackgroundComponent.hpp"
#include "PlayerComponent.hpp"

ECS::Entity::Entity(int id, std::vector<Tag> tags) : _id(id), _tags(tags)
{
}

int ECS::Entity::getId() const
{
    return _id;
}

std::vector<ECS::Tag> ECS::Entity::getTags() const
{
    return _tags;
}

std::shared_ptr<ECS::AComponent> ECS::Entity::getComponent(int id)
{
    for (auto &component : _components) {
        if (component->getId() == id)
            return component;
    }
    return nullptr;
}

void ECS::Entity::addComponent(std::shared_ptr<ECS::AComponent> component)
{
    _components.push_back(component);
}
