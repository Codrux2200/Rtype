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

            void registerEntity(std::shared_ptr<ECS::Entity> entity, std::string name);

            std::shared_ptr<ECS::Entity> createEntity(std::string name, int id);

        private:
            std::map<std::string, std::shared_ptr<ECS::Entity>> _entities;
    };
}
