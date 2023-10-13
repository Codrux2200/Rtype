/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"

ECS::Entity::Entity(int id) : _id(id)
{
}

int ECS::Entity::getId() const
{
    return _id;
}

void ECS::Entity::addComponent(std::shared_ptr<ECS::AComponent> component)
{
    _components.push_back(component);
}

ECS::Entity::Entity(const ECS::Entity &entity, int id) : _id(id)
{
    for (auto &component : entity._components) {
        _components.push_back(component->clone());
    }
    _id = id;
}

std::vector<std::shared_ptr<ECS::IComponent>> ECS::Entity::getComponents() const
{
    return _components;
}
