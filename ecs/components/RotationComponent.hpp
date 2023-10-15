/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** rotationComponent
*/

#ifndef ROTATIONCOMPONENT_HPP_
#define ROTATIONCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Rotation component
     *
     */
    class RotationComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new rotation Component object
             *
             * @param rotation, uid
             */
            RotationComponent(float rotation);
            /**
             * @brief Destroy the rotation Component object
             *
             */
            ~RotationComponent() = default;
            /**
             * @brief Get the rotation Value object
             *
             * @return std::vector<float>
             */
            std::vector<float> getFloatValue() const;
            /**
             * @brief Set the rotation Value object
             * 
             * @param rotation 
             */
            void setFloatValue(float rotation);
            /**
             * @brief clone the component
             * 
             * @return std::shared_ptr<IComponent> 
             */
            std::shared_ptr<IComponent> clone() const final;
        protected:
        private:
            /**
             * @brief define the rotation of the entity
             *
             */
            float _rotation;
    };
}

#endif /* !ROTATIONCOMPONENT_HPP_ */
