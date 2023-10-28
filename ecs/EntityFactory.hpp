/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EntityFactory
*/

#pragma once

#include <map>
#include <memory>
#include <string>
#include "Entity.hpp"

namespace ECS {
    class EntityFactory {
        public:
            EntityFactory();

            ~EntityFactory();

            void registerEntity(const std::shared_ptr<ECS::Entity>& entity, const std::string& name);

            std::shared_ptr<ECS::Entity> createEntity(const std::string& name, int id);

            int ids = 4;

        private:
            std::map<std::string, std::shared_ptr<ECS::Entity>> _entities;
    };
}
