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
        PlayerComponent(int uid, const std::string& spritePath);
        /**
         * @brief Destroy the player Component object
         */
        ~PlayerComponent();
        /**
         * @brief Set the sprite path for the player entity
         *
         * @param newSpritePath The path to the new sprite image
         */
        void setSprite(const std::string& newSpritePath);
        /**
         * @brief Get the sprite path for the player entity
         *
         * @return std::string
         */
        std::string getSprite() const;

    protected:
    private:
        std::string spritePath;
    };
}
 

#endif /* !PLAYERCOMPONENT_HPP_ */
