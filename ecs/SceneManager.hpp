/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_
#include <map>
#include "Scene.hpp"

namespace ECS {
    /**
     * @brief SceneManager class
     * 
     */
    class SceneManager {
        public:
            /**
             * @brief Construct a new Scene Manager object
             * 
             */
            SceneManager();
            /**
             * @brief Destroy the Scene Manager object
             * 
             */
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
