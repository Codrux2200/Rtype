/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include <vector>
#include <memory>
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Entity class
     *
     */
    class Entity {
        public:
            /**
             * @brief Construct a new Entity object
             *
             * @param id
             */
            Entity(int id);
            /**
             * @brief Destroy the Entity object
             *
             */
            ~Entity() = default;

            Entity(const Entity &entity, int id);

            /**
             * @brief Get the Id object
             *
             * @return int
             */
            [[nodiscard]] int getId() const;

            /**
             * @brief Retrieves a specific type of component from the entity.
             *
             * This template function attempts to find and return a component of type T.
             * If such a component doesn't exist, it returns nullptr.
             *
             * @tparam T The type of the component to retrieve.
             * @return A shared pointer to the component of type T, or nullptr if not found.
             */
            template<typename T>
            std::shared_ptr<T> getComponent() {
                for (auto &component : _components) {
                    std::shared_ptr<T> comp = std::dynamic_pointer_cast<T>(component);
                    if (comp)
                        return comp;
                }
                return nullptr;
            }

            void addComponent(std::shared_ptr<AComponent> component);

            /**
             * @brief Retrieves all components of a specific type from the entity.
             *
             * This template function finds and returns all components of type T.
             *
             * @tparam T The type of the components to retrieve.
             * @return A vector of shared pointers to the components of type T.
             */
            [[nodiscard]] std::vector<std::shared_ptr<IComponent>> getComponents() const;

            /** @brief Indicates whether the entity is currently active / enabled. */
            bool isEnabled = true;

        private:
            /**
             * @brief define the unique id of the entity
             *
             */
            int _id;

            /** @brief List of components attached to this entity. */
            std::vector<std::shared_ptr<IComponent>> _components;

    };

}

#endif /* !ENTITY_HPP_ */
