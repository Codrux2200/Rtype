/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "ASystem.hpp"

namespace ECS {
    /**
     * @brief Game System
     * 
     */
    class GameSystem : public ASystem{
        public:
            /**
             * @brief Construct a new Game System object
             * 
             */
            GameSystem();
            /**
             * @brief Destroy the Game System object
             * 
             */
            ~GameSystem();
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */