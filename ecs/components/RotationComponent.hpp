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
             * @param uid 
             */
            RotationComponent(int uid);
            /**
             * @brief Destroy the rotation Component object
             * 
             */
            ~RotationComponent();
            /**
             * @brief Get the Rotation object
             * 
             */
            std::vector<int> getValue() const override;
            /**
             * @brief Set the Rotation object
             * 
             * @param rotation 
             */
            void setValue(int rotation, int unused = 0) override;
        protected:
        private:
            /**
             * @brief define the rotation of the entity
             * 
             */
            int _rotation;
    };
}

#endif /* !ROTATIONCOMPONENT_HPP_ */
