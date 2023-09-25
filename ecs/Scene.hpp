/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/
#include <map>
#include <string>
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
        public :
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
            std::map<int, Entity> entitiesList;
            /**
             * @brief define the scene Type
             * 
             */
            SceneType sceneType;
            /**
             * @brief load entities from the specified string
             * 
             * @param entityID 
             */
            void loadEntity(int entityID);
            /**
             * @brief unload entities from the specified string
             * 
             * @param entityID
             */
            void unloadEntity(int entityID);



    };
}

#endif /* !SCENE_HPP_ */
