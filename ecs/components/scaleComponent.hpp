/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scaleComponent
*/

#ifndef SCALECOMPONENT_HPP_
#define SCALECOMPONENT_HPP_
#include "Acomponent.hpp"

class scaleComponent : public ECS::Acomponent {
    public:
        /**
         * @brief Construct a new scale Component object
         * 
         * @param x 
         * @param y 
         * @param uid 
         */
        scaleComponent(int x, int y, int uid);
        /**
         * @brief Destroy the scale Component object
         * 
         */
        ~scaleComponent();
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
        int x;
        /**
         * @brief define the y scale of the entity
         * 
         */
        int y;
};

#endif /* !SCALECOMPONENT_HPP_ */
