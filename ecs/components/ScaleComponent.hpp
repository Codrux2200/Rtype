/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scaleComponent
*/

#ifndef SCALECOMPONENT_HPP_
#define SCALECOMPONENT_HPP_

#include <memory>
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
            ScaleComponent(float x, float y);
            /**
             * @brief Destroy the scale Component object
             *
             */
            ~ScaleComponent() = default;
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

            std::vector<float> getFloatValue() const;

            void setFloatValue(float x, float y);

            std::shared_ptr<IComponent> clone() const final;
        protected:
        private:
            float _x;
            float _y;
    };
}

#endif /* !SCALECOMPONENT_HPP_ */
