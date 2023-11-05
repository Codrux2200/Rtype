/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SceneManager
*/

#pragma once
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
            std::shared_ptr<Scene> &getScene(SceneType sceneType);
            /**
             * @brief Set the Scene object
             *
             * @param sceneType
             * @param scene
             */
            void setScene(SceneType sceneType, std::shared_ptr<Scene> scene);
            /**
             * @brief a boolean to know if the window should close
             *
             */
            bool shouldClose = false;

            /**
             * @brief Set the Current Scene object
             *
             * @param sceneType
             */
            void setCurrentScene(SceneType sceneType);

            /**
             * @brief Get the Current Scene object
             *
             * @return SceneType
             */
            SceneType getSceneType();

            /**
             * @brief Get the Current Scene object
             *
             * @return shared_ptr<Scene>
             */
            std::shared_ptr<Scene> &getCurrentScene();

            std::map<SceneType, std::shared_ptr<Scene>> &getScenes();
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
