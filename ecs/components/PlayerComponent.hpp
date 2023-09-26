/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** playerComponent
*/

#ifndef PLAYERCOMPONENT_HPP_
#define PLAYERCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Player component
     * 
     */
    class PlayerComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new player Component object
             * 
             * @param id
             */
            PlayerComponent(int uid);
            /**
             * @brief Destroy the player Component object
             * 
             */
            ~PlayerComponent();
        protected:
        private:
    };
}

#endif /* !PLAYERCOMPONENT_HPP_ */
