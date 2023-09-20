/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** rotationComponent
*/

#ifndef ROTATIONCOMPONENT_HPP_
#define ROTATIONCOMPONENT_HPP_
#include "Acomponent.hpp"
namespace ECS {
    class RotationComponent : public ECS::Acomponent {
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
            int getRotation() const;
            /**
             * @brief Set the Rotation object
             * 
             * @param rotation 
             */
            void setRotation(float rotation);
        protected:
        private:
            /**
             * @brief define the rotation of the entity
             * 
             */
            float rotation;
    };
}

#endif /* !ROTATIONCOMPONENT_HPP_ */
