#include <iostream>
#include <map>
#include "./system/iSystem.hpp"
#include "SceneManager.hpp"
namespace ECS {
	class core {
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
