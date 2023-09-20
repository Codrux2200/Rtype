/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_
#include "Acomponent.hpp"

class enemyComponent : public ECS::Acomponent {
    public:
        /**
         * @brief Construct a new enemy Component object
         * 
         * @param uid 
         */
        enemyComponent(int uid);
        /**
         * @brief Destroy the enemy Component object
         * 
         */
        ~enemyComponent();
    protected:
    private:
};

#endif /* !ENEMYCOMPONENT_HPP_ */
