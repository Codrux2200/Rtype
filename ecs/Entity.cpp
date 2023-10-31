/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Entity
*/

#include "Entity.hpp"
#include "AGameComponent.hpp"
#include <iostream>

namespace ECS {
    Entity::Entity(int id) : _id(id)
    {
    }

    int Entity::getId() const
    {
        return _id;
    }

    const std::shared_ptr<AComponent>&  Entity::addComponent(const std::shared_ptr<AComponent>& component)
    {
        _components.push_back(component);
        return component;
    }

    Entity::Entity(const Entity &entity, int id) : _id(id)
    {
        for (auto &component : entity._components) {
            if (component == nullptr)
                continue;
            _components.push_back(component->clone());
        }
        _id = id;
        updateGameComponents();
    }

    std::vector<std::shared_ptr<IComponent>> Entity::getComponents() const
    {
        return _components;
    }

    bool Entity::onDestroy(float dt)
    {
        bool canBeDestroyed = true;

        for (auto &component : _components)
            if (!component->onDestroy(*this, deathReason, dt))
                canBeDestroyed = false;
        return canBeDestroyed;
    }

    void Entity::updateGameComponents()
    {
        _gameComponents.clear();
        for (auto &component : _components) {
            auto casted = std::dynamic_pointer_cast<AGameComponent>(component);
            if (casted) {
                _gameComponents.push_back(casted);
                std::cout << "Added game component" << std::endl;
            }
        }
    }

    std::vector<std::shared_ptr<AGameComponent>>
    Entity::getGameComponents() const
    {
        return _gameComponents;
    }
}