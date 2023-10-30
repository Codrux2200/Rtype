/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EntityFactory
*/

#include <iostream>
#include "EntityFactory.hpp"

ECS::EntityFactory::EntityFactory()
{
}

ECS::EntityFactory::~EntityFactory()
{
}

void ECS::EntityFactory::registerEntity(const std::shared_ptr<ECS::Entity>& entity, const std::string& name)
{
    _entities[name] = std::make_shared<ECS::Entity>(*entity, -1);
    std::cout << "Registering entity " << name << std::endl;
    std::cout << "Entity " << name << " has " << _entities[name]->getComponents().size() << " components" << std::endl;
}

std::shared_ptr<ECS::Entity> ECS::EntityFactory::createEntity(const std::string& name, int id)
{
    std::shared_ptr<ECS::Entity> entity = _entities[name];

    if (!entity) {
        std::cerr << "Entity \"" << name << "\" not found" << std::endl;
        return nullptr;
    }
    return std::make_shared<ECS::Entity>(*entity, id);
}
