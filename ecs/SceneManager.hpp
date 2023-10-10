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
            SceneManager() = default;
            SceneManager(std::map<SceneType, std::shared_ptr<Scene>> scenes);
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
            std::shared_ptr<Scene> &getScene();
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

            /**
             * @brief Set the Current Scene object
             *
             * @param sceneType
             */
            void setCurrentScene(SceneType sceneType);
        protected:
        private:
            /**
             * @brief a map to get a scene from a SceneType
             *
             */
            std::map<SceneType, std::shared_ptr<Scene>> _scenes;
            /**
             * @brief stock the current Scene from a SceneType key
             *
             */
            SceneType _currentScene;

    };
}

#endif /* !SCENEMANAGER_HPP_ */
