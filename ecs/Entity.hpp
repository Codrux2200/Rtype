/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include <algorithm>
#include <memory>
#include <vector>
#include "AComponent.hpp"
#include "DeadData.hpp"

namespace ECS {
    /**
     * @brief Entity class
     *
     */

    class AGameComponent;

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

            enum EntityType {
                PLAYER,
                ENEMY_CLASSIC,
                PLAYER_BULLET,
                BOSS,
                BOSS_BULLET,
                UNKNOWN
            };

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
                auto it = std::find_if(_components.begin(), _components.end(), [](const std::shared_ptr<IComponent> &component) {
                    return std::dynamic_pointer_cast<T>(component);
                });
                if (it == _components.end())
                    return nullptr;
                return std::dynamic_pointer_cast<T>(*it);
            }

            template<typename T>
            std::vector<std::shared_ptr<T>> getComponents() {
                std::vector<std::shared_ptr<T>> components;

                for (auto component : _components) {
                    if (component == nullptr)
                        continue;
                    auto casted = std::dynamic_pointer_cast<T>(component);
                    if (casted)
                        components.push_back(casted);
                }
                return components;
            }

            const std::shared_ptr<AComponent> &addComponent(const std::shared_ptr<AComponent>& component);

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
            Network::data::DeathReason deathReason = Network::data::ALIVE;

            /**
             * @brief Destroy the Entity object
             *
             * @return true if the entity can be destroyed
             * @return false if the entity can't be destroyed now, it can be used to do actions by components before destroying the entity
             */
            virtual bool onDestroy(float dt);

            /**
             * @brief Get the Game Components objects that are int stored as cache
             */

            void updateGameComponents();

            [[nodiscard]] std::vector<std::shared_ptr<AGameComponent>> getGameComponents() const;

        private:
            std::vector<std::shared_ptr<AGameComponent>> _gameComponents;
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
