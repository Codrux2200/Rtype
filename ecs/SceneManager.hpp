/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_
#include <map>
#include "scene.hpp"

namespace ECS{
    class SceneManager {
        public:
            SceneManager();
            ~SceneManager();
            
        protected:
        private:
            /**
             * @brief a map to get a scene from a SceneType
             * 
             */
            std::map<SceneType ,Scene> _scenes;
            /**
             * @brief stock the current Scene from a SceneType key
             * 
             */
            SceneType _currentScene;
            /**
             * @brief to define
             * 
             */
            bool _shouldClose;

    };
}

#endif /* !SCENEMANAGER_HPP_ */
