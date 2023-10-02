/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** hitboxComponent
*/

#ifndef HITBOXCOMPONENT_HPP_
#define HITBOXCOMPONENT_HPP_
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Hitbox component
     * 
     */
    class HitboxComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new hitbox Component object
             * 
             * @param x 
             * @param y
             * @param uid
             */
            HitboxComponent(int x, int y, int uid);
            /**
             * @brief Destroy the hitbox Component object
             * 
             */
            ~HitboxComponent();
            /**
             * @brief Get the X hitbox object
             * 
             * @return int
             */
            int getX() const;
            /**
             * @brief Get the Y hitbox object
             * 
             * @return int
             */
            int getY() const;
        protected:
        private:
            /**
             * @brief define the x hitbox of the entity
             * 
             */
            int _x;
            /**
             * @brief define the y hitbox of the entity
             * 
             */
            int _y;
    };
}

#endif /* !HITBOXCOMPONENT_HPP_ */