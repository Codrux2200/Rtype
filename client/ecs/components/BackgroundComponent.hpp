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
    class BackgroundComponent
    {
    public:
        BackgroundComponent();

        void update(float deltaTime, const sf::Vector2u& screenSize);
        void draw(sf::RenderWindow &window);

    private:
        std::vector<sf::Texture> backgroundTextures;
        sf::Texture foregroundTexture;

        std::vector<std::unique_ptr<sf::Sprite>> backgroundLayers;
        std::unique_ptr<sf::Sprite> foreground;

        std::vector<float> backgroundSpeeds;
        float foregroundSpeed;

        std::vector<sf::Vector2f> backgroundPositions;
        sf::Vector2f foregroundPosition;
    };
}

#endif // BACKGROUND_COMPONENT_HPP
