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

            int addEntity(std::shared_ptr<Entity> entity);

            void removeEntity(int entityID);

            [[nodiscard]] SceneType getSceneType() const;

            std::shared_ptr<Entity> getEntityByID(int entityID);

            template <class T>
            std::vector<std::shared_ptr<Entity>> getEntitiesWithComponent()
            {
                std::vector<std::shared_ptr<Entity>> entities;

                for (auto &entity : entitiesList) {
                    if (entity->getComponent<T>())
                        entities.push_back(entity);
                }
                return entities;
            }

            private:
            int _entityID;
            SceneType _sceneType;

    };
}

#endif /* !SCENE_HPP_ */
