/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** hitboxComponent
*/

#ifndef HITBOXCOMPONENT_HPP_
#define HITBOXCOMPONENT_HPP_
#include "Acomponent.hpp"

class hitboxComponent : public ECS::Acomponent {
    public:
        /**
         * @brief Construct a new hitbox Component object
         * 
         * @param x 
         * @param y
         * @param uid
         */
        hitboxComponent(int x, int y, int uid);
        /**
         * @brief Destroy the hitbox Component object
         * 
         */
        ~hitboxComponent();
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
        int x;
        int y;
};


#endif /* !HITBOXCOMPONENT_HPP_ */
