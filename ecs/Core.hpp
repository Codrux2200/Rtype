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
		std::map<std::string, ISystem> System;
		/**
		 * @brief the actual Scene Manager
		 * 
		 */
		SceneManager sceneManager;

	};
}

#endif /* !CORE_HPP_ */