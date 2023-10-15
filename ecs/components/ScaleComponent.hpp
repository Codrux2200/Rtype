/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scaleComponent
*/

#ifndef SCALECOMPONENT_HPP_
#define SCALECOMPONENT_HPP_
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Scale component
     * 
     */
    class ScaleComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new scale Component object
             * 
             * @param x 
             * @param y 
             * @param uid 
             */
            ScaleComponent(int x, int y, int uid);
            /**
             * @brief Destroy the scale Component object
             * 
             */
            ~ScaleComponent();
            /**
             * @brief Set the X object
             * 
             * @param x
             */
            void setX(int x);
            /**
             * @brief Set the Y object
             * 
             * @param y
             */
            void setY(int y);
            /**
             * @brief Get the X object
             * 
             * @return int
             */
            int getX();
            /**
             * @brief Get the Y object
             * 
             * @return int
             */
            int getY();
        protected:
        private:
            /**
             * @brief define the x scale of the entity
             * 
             */
            int _x;
            /**
             * @brief define the y scale of the entity
             * 
             */
            int _y;
    };
}

#endif /* !SCALECOMPONENT_HPP_ */
