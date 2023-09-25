/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "ASystem.hpp"

namespace ECS {
    /**
     * @brief Graphic System
     * 
     */
    class GraphicSystem : public ASystem{
        public:
            /**
             * @brief Construct a new Graphic System object
             * 
             */
            GraphicSystem();
            /**
             * @brief Destroy the Graphic System object
             * 
             */
            ~GraphicSystem();
        protected:
        private:
    };
};
#endif /* !GRAPHICSYSTEM_HPP_ */
