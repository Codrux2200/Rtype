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
            /**
             * @brief Set the player of the entity
             * 
             * @param player
             */
            void setValue(int player, int unused = 0) final;
            /**
             * @brief Get the player of the entity
             * 
             * @return std::vector<int>
             */
            std::vector<int> getValue() const final;
        protected:
        private:
    };
}

#endif /* !PLAYERCOMPONENT_HPP_ */
