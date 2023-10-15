/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** positionComponent
*/

#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Position component
     * 
     */
    class PositionComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new position Component object
             * 
             * @param x 
             * @param y
             * @param uid
             */
            PositionComponent(int x, int y, int uid);
            /**
             * @brief Destroy the position Component object
             * 
             */
            ~PositionComponent();
            /**
             * @brief Get the X position object
             * 
             * @return int
             */
            int getX() const;
            /**
             * @brief Get the Y position object
             * 
             * @return int
             */
            int getY() const;
            /**
             * @brief Set the X position object
             * 
             * @param x 
             */
            void setX(int x);
            /**
             * @brief Set the Y position object
             * 
             * @param y 
             */
            void setY(int y);
            
            /**
             * @brief move the entity right
             * 
             * @param y 
             */
            void moveRight(int x);
            /**
             * @brief move the entity left
             * 
             * @param x 
             */
            void moveLeft(int x);
            /**
             * @brief move the entity up
             * 
             * @param y 
             */
            void moveUp(int y);
            /**
             * @brief move the entity down
             * 
             * @param y 
             */
            void moveDown(int y);
        protected:
        private:
            /**
             * @brief define the x position of the entity
             * 
             */
            int _x;
            /**
             * @brief define the y position of the entity
             * 
             */
            int _y;
    };
}

#endif /* !POSITIONCOMPONENT_HPP_ */
