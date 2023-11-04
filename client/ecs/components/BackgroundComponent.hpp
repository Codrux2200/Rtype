/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BackgroundComponent
*/

#ifndef BACKGROUND_COMPONENT_HPP
#define BACKGROUND_COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "../AComponent.hpp"
#include <vector>
#include <memory>

namespace ECS
{
    /**
     * @brief Background Component
     */
    class BackgroundComponent
    {
    public:
        /**
         * @brief Construct a new Background Component object
         * 
         * @param windowWidth the window width
         * @param windowHeight the window height
        */
        BackgroundComponent(int windowWidth, int windowHeight);

        /**
         * @brief update the background
         * 
         * @param deltaTime the delta time
         * @param screenSize the screen size
        */
        void update(float deltaTime, const sf::Vector2i& screenSize);
        void draw(sf::RenderWindow &window);

    private:
        /**
         * @brief vector of background textures
        */
        std::vector<sf::Texture> backgroundTextures;
        /**
         * @brief foreground texture
        */
        sf::Texture foregroundTexture;

        /**
         * @brief vector of background sprites
        */
        std::vector<std::shared_ptr<sf::Sprite>> backgroundLayers;
        /**
         * @brief foreground sprite
        */
        std::shared_ptr<sf::Sprite> foreground;

        /**
         * @brief vector of background speeds
        */
        std::vector<float> backgroundSpeeds;
        /**
         * @brief foreground speed
        */
        float foregroundSpeed;

        /**
         * @brief vector of background positions
        */
        std::vector<sf::Vector2f> backgroundPositions;
        /**
         * @brief foreground position
        */ 
        sf::Vector2f foregroundPosition;
    };
}

#endif // BACKGROUND_COMPONENT_HPP
