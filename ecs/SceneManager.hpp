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
            /**
             * @brief Get the Scene object
             * 
             * @param sceneType 
             * @return Scene 
             */
            Scene &getScene(SceneType sceneType);
            /**
             * @brief Set the Scene object
             * 
             * @param sceneType 
             * @param scene 
             */
            void setScene(SceneType sceneType, Scene scene);
            /**
             * @brief a boolean to know if the window should close
             * 
             */
            bool shouldClose;
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

    };
}

#endif /* !SCENEMANAGER_HPP_ */
