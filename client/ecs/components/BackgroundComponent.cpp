/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Background Component
*/

#include "BackgroundComponent.hpp"

namespace ECS
{
    BackgroundComponent::BackgroundComponent()
    {
        // Load your background textures and set their speeds here
        // Replace "backgroundTexture1", "backgroundTexture2", etc. with your actual textures
        // Adjust the speed values as needed
        backgroundTextures.push_back(sf::Texture());
        backgroundTextures[0].loadFromFile("assets/6Background.png");
        backgroundSpeeds.push_back(0.2f);

        backgroundTextures.push_back(sf::Texture());
        backgroundTextures[1].loadFromFile("assets/6Background.png");
        backgroundSpeeds.push_back(0.1f);

        // Load your foreground texture and set its speed here
        // Replace "foregroundTexture" with your actual foreground texture
        foregroundTexture.loadFromFile("foreground.png");
        foregroundSpeed = 0.3f;

        // Initialize background sprites
        for (int i = 0; i < backgroundTextures.size(); ++i)
        {
            backgroundLayers.push_back(std::make_unique<sf::Sprite>(backgroundTextures[i]));
            backgroundPositions.push_back(sf::Vector2f(0.0f, 0.0f));
        }

        // Initialize foreground sprite
        foreground = std::make_unique<sf::Sprite>(foregroundTexture);
        foregroundPosition = sf::Vector2f(0.0f, 0.0f);
    }

    void BackgroundComponent::update(float deltaTime, const sf::Vector2u& screenSize)
    {
        // Update the background positions based on their speeds and deltaTime
        for (int i = 0; i < backgroundLayers.size(); ++i)
        {
            backgroundPositions[i].x -= backgroundSpeeds[i] * deltaTime;
            if (backgroundPositions[i].x < -screenSize.x)
            {
                backgroundPositions[i].x = 0.0f;
            }
            backgroundLayers[i]->setPosition(backgroundPositions[i]);
        }

        // Update the foreground position based on its speed and deltaTime
        foregroundPosition.x -= foregroundSpeed * deltaTime;
        if (foregroundPosition.x < -screenSize.x)
        {
            foregroundPosition.x = 0.0f;
        }
        foreground->setPosition(foregroundPosition);
    }

    void BackgroundComponent::draw(sf::RenderWindow& window)
    {
        // Draw the background layers
        for (const auto& backgroundLayer : backgroundLayers)
        {
            window.draw(*backgroundLayer);
        }

        // Draw the foreground
        window.draw(*foreground);
    }
}

