/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** playerComponent
*/

#ifndef PLAYERCOMPONENT_HPP_
#define PLAYERCOMPONENT_HPP_
#include "../AComponent.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

namespace ECS {
    /**
     * @brief Player component
     */
    class PlayerComponent : public ECS::AComponent {
    public:
        /**
         * @brief Construct a new player Component object
         *
         * @param uid
         * @param spritePath The path to the player sprite image
         */
        PlayerComponent();
        /**
         * @brief Destroy the player Component object
         */
        ~PlayerComponent();
        /**
         * @brief Update the component
         *
         * @param positions the vector of the positions of the entity
         */
        void update(const std::vector<int> positions);
    };
}


#endif /* !PLAYERCOMPONENT_HPP_ */
