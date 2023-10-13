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
            int getId() const;

            // Templates impose to write the implementation in the header file
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

            std::vector<std::shared_ptr<IComponent>> getComponents() const;

            bool isEnabled = true;

        private:
            /**
             * @brief define the id of the entity
             *
             */
            int _id;

            /**
             * @brief stock component
             *
             */
            std::vector<std::shared_ptr<IComponent>> _components;

    };

}

#endif /* !ENTITY_HPP_ */
