/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** hitboxComponent
*/

#ifndef HITBOXCOMPONENT_HPP_
#define HITBOXCOMPONENT_HPP_
#include "Acomponent.hpp"

namespace ECS {
    class HitboxComponent : public ECS::Acomponent {
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
            int x;
            /**
             * @brief define the y hitbox of the entity
             * 
             */
            int y;
    };
}

#endif /* !HITBOXCOMPONENT_HPP_ */
