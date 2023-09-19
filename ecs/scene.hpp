/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** scene
*/
#include <map>
#include "entity.hpp"
#ifndef SCENE_HPP_
#define SCENE_HPP_

namespace ECS{
    enum SceneType{
        NONE = 0,
        MAIN_MENU = 1,
        HELP = 2,
        ENDGAME = 3,
        DEATH = 4,
        PAUSE = 5
    };

    class Scene{
        public :
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
        private:
            /**
             * @brief load entities from the specified string
             * 
             * @param entityName 
             */
            void loadEntity(std::string entityName);
            /**
             * @brief unload entities from the specified string
             * 
             * @param entityName 
             */
            void unloadEntity(std::string entityName);



    };
}

#endif /* !SCENE_HPP_ */
