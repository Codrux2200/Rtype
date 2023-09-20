/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** velocityComponent
*/

#ifndef VELOCITYCOMPONENT_HPP_
#define VELOCITYCOMPONENT_HPP_
#include "Acomponent.hpp"

class velocityComponent : public ECS::Acomponent {
    public:
        /**
         * @brief Construct a new velocity Component object
         * 
         * @param uid 
         */
        velocityComponent(int uid);
        /**
         * @brief Destroy the velocity Component object
         * 
         */
        ~velocityComponent();
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
        int velocity;
};

#endif /* !VELOCITYCOMPONENT_HPP_ */
