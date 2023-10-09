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
             * @brief Get the X and Y position object
             * 
             * @return std::vector<int>
             */
            std::vector<int> getValue() const final;
            /**
             * @brief Set the X and Y position object
             * 
             * @param x 
             * @param y 
             */
            void setValue(int x, int y) final;
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
