/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** playerComponent
*/

#ifndef PLAYERCOMPONENT_HPP_
#define PLAYERCOMPONENT_HPP_
#include "Acomponent.hpp"

class playerComponent : public ECS::Acomponent {
    public:
        /**
         * @brief Construct a new player Component object
         * 
         * @param id
         */
        playerComponent(int uid);
        /**
         * @brief Destroy the player Component object
         * 
         */
        ~playerComponent();
    protected:
    private:
};

#endif /* !PLAYERCOMPONENT_HPP_ */
