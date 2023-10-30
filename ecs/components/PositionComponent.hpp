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
            PositionComponent(float x, float y);
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
            std::vector<int> getValue() const override;
            /**
             * @brief Set the X and Y position object
             *
             * @param x
             * @param y
             */
            void setValue(std::vector<int> values) override;

            /**
             * @brief move the entity
             *
             * @param x
             * @param y
             */
            void move(float x, float y);

            std::shared_ptr<IComponent> clone() const override;
            float x;
            float y;
        protected:
        private:
            /**
             * @brief define the x position of the entity
             *
             */
            /**
             * @brief define the y position of the entity
             *
             */
    };
}

#endif /* !POSITIONCOMPONENT_HPP_ */
