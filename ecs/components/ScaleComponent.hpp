/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scaleComponent
*/

#ifndef SCALECOMPONENT_HPP_
#define SCALECOMPONENT_HPP_
#include "../AComponent.hpp"

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
             * @brief Get the X and Y scale object
             * 
             * @return std::vector<int>
             */
            std::vector<int> getValue() const final;
            /**
             * @brief Set the X and Y scale object
             * 
             * @param x 
             * @param y 
             */
            void setValue(int x, int y) final;
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
