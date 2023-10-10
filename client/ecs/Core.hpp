/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "ISystem.hpp"
#include "SceneManager.hpp"
#include "Connection.hpp"

namespace ECS {
	/**
	 * @brief the core of the ECS
	 *
	 */
	class Core {
	    public:
            /**
             * @brief Construct a new Core object
             *
             */
            Core();
            /**
             * @brief Destroy the Core object
             *
             */
            ~Core() = default;
            /**
             * @brief a map of the system with a key string
             *
             */
            //std::map<std::string, ISystem> system;
            /**
             * @brief the actual Scene Manager
             *
             */
            SceneManager sceneManager;
            /**
             * @brief the main loop of the ECS
             *
             */
            void mainLoop(RType::Connection &connection);
        private:
            std::shared_ptr<ECS::Scene> _initMainMenuScene();
            std::vector<std::unique_ptr<ECS::ISystem>> _systems;
	};
}

#endif /* !CORE_HPP_ */
