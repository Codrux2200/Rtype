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
     * @brief Tag enum
     *
     */
    enum Tag{
        MOVABLE = 0,
        AUDIBLE = 1,
        DESTROYABLE = 2,
        COLIDLE = 3,
    };
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
            Entity(int id, std::vector<Tag> tags);
            /**
             * @brief Destroy the Entity object
             *
             */
            ~Entity() = default;
            /**
             * @brief Get the Id object
             *
             * @return int
             */
            int getId() const;
            /**
             * @brief Get the Tags object
             *
             * @return std::vector<Tag>
             */
            std::vector<Tag> getTags() const;

            std::shared_ptr<AComponent> getComponent(int id);

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

            private :
                /**
                 * @brief define the tag for the entity
                 *
                 */
                std::vector<Tag> _tags;
                /**
                 * @brief define the id of the entity
                 *
                 */
                int _id;

                /**
                 * @brief stock component
                 *
                 */
                std::vector<std::shared_ptr<AComponent>> _components;

    };

}

#endif /* !ENTITY_HPP_ */
