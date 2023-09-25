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
#include "ISystem.hpp"
#include "SceneManager.hpp"

namespace ECS {
	/**
	 * @brief the core of the ECS
	 * 
	 */
	class Core {
	public :
		/**
		 * @brief a map of the system with a key string
		 * 
		 */
		std::map<std::string, ISystem> system;
		/**
		 * @brief the actual Scene Manager
		 * 
		 */
		SceneManager sceneManager;
		/**
		 * @brief the main loop of the ECS
		 * 
		 */
		void mainLoop();

	};
}

#endif /* !CORE_HPP_ */
