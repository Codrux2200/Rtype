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
            /** @brief Default constructor for the EntityFactory class. */
            EntityFactory();

            /** @brief Destructor for the EntityFactory class. */
            ~EntityFactory();

              /**
             * @brief Registers an entity with a given name.
             *
             * @param entity The entity to register.
             * @param name The name associated with the entity type.
             */
            void registerEntity(const std::shared_ptr<ECS::Entity>& entity, const std::string& name);

            /**
             * @brief Creates and returns an entity of a specified type.
             *
             * @param name The name of the entity type to create.
             * @param id The unique ID for the new entity.
             * @return A shared pointer to the created entity.
             */
            std::shared_ptr<ECS::Entity> createEntity(const std::string& name, int id);

            int ids = 4;

        private:
            /** @brief Map associating entity names to their corresponding entity objects. */
            std::map<std::string, std::shared_ptr<ECS::Entity>> _entities;
    };
}
