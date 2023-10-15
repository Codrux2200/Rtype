/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** shootComponent
*/

#ifndef SHOOTCOMPONENT_HPP_
#define SHOOTCOMPONENT_HPP_
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Shoot component
     * 
     */
    class ShootComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new shoot Component object
             * 
             * @param uid 
             */
            ShootComponent(int uid, int shootSpeed, int shootDamage);
            /**
             * @brief Destroy the shoot Component object
             * 
             */
            ~ShootComponent();
            /**
             * @brief Get the Shoot Speed object
             * 
             * @return int 
             */
            int getShootSpeed() const;
            /**
             * @brief Get the Shoot Damage object
             * 
             * @return int 
             */
            int getShootDamage() const;
            /**
             * @brief Set the Shoot Speed object
             * 
             * @param shootSpeed 
             */
            void setShootSpeed(int shootSpeed);
            /**
             * @brief Set the Shoot Damage object
             * 
             * @param shootDamage 
             */
            void setShootDamage(int shootDamage);
        protected:
        private:
            /**
             * @brief define the shoot speed of the entity
             * 
             */
            int _shootSpeed;
            /**
             * @brief define the shoot damage of the entity
             * 
             */
            int _shootDamage;
    };
}

#endif /* !SHOOTCOMPONENT_HPP_ */
