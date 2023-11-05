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
    class ScaleComponent : public AComponent {
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
             * @brief Get the scale Value object
             *
             * @return std::vector<float>
             */
            std::vector<float> getFloatValue() const;
            /**
             * @brief Set the scale Value object
             *
             * @param x
             * @param y
             */
            void setFloatValue(float x, float y);
        /**
             * @brief clone the component
             *
             * @return std::shared_ptr<IComponent>
             */
            std::shared_ptr<IComponent> clone() const final;

            /**
             * @brief define the X scale of the entity
             *
             */
            float x;
            /**
             * @brief define the Y scale of the entity
             *
             */
            float y;
        protected:
        private:
    };
}

#endif /* !SCALECOMPONENT_HPP_ */
