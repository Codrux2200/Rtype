/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <map>
#include <string>
#include <memory>
#include "Entity.hpp"

namespace ECS {
    /**
     * @brief SceneType enum
     *
     */
    enum SceneType{
        NONE = -1,
        MAIN_MENU,
        GAME,
        HELP,
        ENDGAME,
        DEATH,
        PAUSE
    };
    /**
     * @brief Scene class
     *
     */
    class Scene {
        public:
            /**
             * @brief Construct a new Scene object
             *
             * @param sceneType
             */
            explicit Scene(SceneType sceneType);
            /**
             * @brief Destroy the Scene object
             *
             */
            ~Scene();
            /**
             * @brief stock entities with an specified key
             *
             */
            std::vector<std::shared_ptr<Entity>> entitiesList;

            /**
             * @brief add an entity to the scene
             *
             * @param entity
             * @return int
             */
            int addEntity(std::shared_ptr<Entity> entity);

            /**
             * @brief remove an entity from the scene
             *
             * @param entityID
             */
            void removeEntity(int entityID);

            /**
             * @brief Get the Scene Type object
             *
             * @return SceneType
             */
            [[nodiscard]] SceneType getSceneType() const;

            /**
             * @brief Get the Entity By ID object
             *
             * @param entityID
             * @return std::shared_ptr<Entity>
             */
            std::shared_ptr<Entity> getEntityByID(int entityID);

            template <class T>
            std::vector<std::shared_ptr<Entity>> getEntitiesWithComponent()
            {
                std::vector<std::shared_ptr<Entity>> entities;

                for (auto &entity : entitiesList) {
                    if (entity == nullptr)
                        continue;
                    if (entity->getComponent<T>())
                        entities.push_back(entity);
                }
                return entities;
            }

            void removeEntitiesToDestroy();

        private:
            /** @brief The ID of the entity. */
            int _entityID;
            /** @brief The type of the scene. */
            SceneType _sceneType;

    };
}

#endif /* !SCENE_HPP_ */
