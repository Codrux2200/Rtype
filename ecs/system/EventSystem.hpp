/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EventSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "ASystem.hpp"

namespace ECS {
    /**
     * @brief Event System
     * 
     */
    class EventSystem : public ASystem{
        public:
            /**
             * @brief Construct a new Event System object
             * 
             */
            EventSystem();
            /**
             * @brief Destroy the Event System object
             * 
             */
            ~EventSystem();      
        protected:
        private:
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
