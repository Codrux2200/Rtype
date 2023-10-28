/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"

namespace ECS {
    Entity::Entity(int id) : _id(id)
    {
    }

    int Entity::getId() const
    {
        return _id;
    }

    void Entity::addComponent(const std::shared_ptr<AComponent>& component)
    {
        _components.push_back(component);
    }

    Entity::Entity(const Entity &entity, int id) : _id(id)
    {
        for (auto &component : entity._components) {
            if (component == nullptr)
                continue;
            _components.push_back(component->clone());
        }
        _id = id;
    }

    std::vector<std::shared_ptr<IComponent>> Entity::getComponents() const
    {
        return _components;
    }

    bool Entity::onDestroy()
    {
        bool canBeDestroyed = true;

        for (auto &component : _components)
            if (!component->onDestroy(*this, deathReason))
                canBeDestroyed = false;
        return canBeDestroyed;
    }
}