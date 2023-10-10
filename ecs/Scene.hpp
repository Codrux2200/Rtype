/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/
#include <map>
#include <string>
#include <memory>
#include "Entity.hpp"
#ifndef SCENE_HPP_
#define SCENE_HPP_

namespace ECS {
    /**
     * @brief SceneType enum
     *
     */
    enum SceneType{
        NONE = 0,
        MAIN_MENU = 1,
        HELP = 2,
        ENDGAME = 3,
        DEATH = 4,
        PAUSE = 5
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
            Scene(SceneType sceneType);
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

            SceneType getSceneType() const;

        private:
            int _entityID;
            SceneType _sceneType;

    };
}

#endif /* !SCENE_HPP_ */
