/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** velocityComponent
*/

#ifndef VELOCITYCOMPONENT_HPP_
#define VELOCITYCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Velocity component
     * 
     */
    class VelocityComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new velocity Component object
             * 
             * @param uid 
             */
            VelocityComponent(int uid);
            /**
             * @brief Destroy the velocity Component object
             * 
             */
            ~VelocityComponent();
            /**
             * @brief Set the velocity of the entity
             * 
             * @param velocity
             */
            void setVelocity(int velocity);
            /**
             * @brief Get the velocity of the entity
             * 
             * @return int
             */
            int getVelocity() const;        
        protected:
        private:
            int _velocity;
    };
}

#endif /* !VELOCITYCOMPONENT_HPP_ */