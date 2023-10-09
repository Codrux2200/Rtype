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
        /**
         * @brief Update the component
         * 
         * @param positions the vector of the positions of the entity
         */
        void update(const std::vector<int> positions);
        /**
         * @brief Draw the components
         * 
         * @param window the renderWindow
        */
       void draw(sf::RenderWindow &window);
    protected:
    private:
        std::string _spritePath;
        std::unique_ptr<sf::Sprite> _sprite;
        sf::Texture _texture;
    };
}
 

#endif /* !PLAYERCOMPONENT_HPP_ */
