/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Background Component
*/

#include <iostream>
#include "BackgroundComponent.hpp"
#include "ConvertPath.hpp"

namespace ECS
{
    BackgroundComponent::BackgroundComponent(int windowWidth, int windowHeight)
    {
        RType::ConvertPath convertPath;
        // Load your background textures and set their speeds here
        // Replace "backgroundTexture1", "backgroundTexture2", etc. with your actual textures
        // Adjust the speed values as needed
        backgroundTextures.push_back(sf::Texture());
        if (!backgroundTextures[0].loadFromFile(convertPath.convertPath("assets/background/6Background.png"))) {
            std::cout << "Error loading background texture" << std::endl;
            return;
        }
        backgroundSpeeds.push_back(20.0f);

        backgroundTextures.push_back(sf::Texture());
        if (!backgroundTextures[1].loadFromFile(convertPath.convertPath("assets/background/6Background.png"))) {
            std::cout << "Error loading background texture" << std::endl;
            return;
        }
        backgroundSpeeds.push_back(20.0f);

        backgroundTextures.push_back(sf::Texture());
        if (!backgroundTextures[2].loadFromFile(convertPath.convertPath("assets/background/1Background.png"))) {
            std::cout << "Error loading background texture" << std::endl;
            return;
        }
        backgroundSpeeds.push_back(40.0f);

        backgroundTextures.push_back(sf::Texture());
        if (!backgroundTextures[3].loadFromFile(convertPath.convertPath("assets/background/1Background.png"))) {
            std::cout << "Error loading background texture" << std::endl;
            return;
        }
        backgroundSpeeds.push_back(40.0f);

        float backgroundWRatio = 0.0f;
        float backgroundHRatio = 0.0f;


        // Initialize background sprites
        for (int i = 0; i < backgroundTextures.size(); ++i)
        {
            backgroundWRatio = static_cast<float>(windowWidth) / static_cast<float>(backgroundTextures[i].getSize().x);
            backgroundHRatio = static_cast<float>(windowHeight) / static_cast<float>(backgroundTextures[i].getSize().y);
            backgroundLayers.push_back(std::make_unique<sf::Sprite>(backgroundTextures[i]));
            backgroundLayers[i]->setScale(sf::Vector2f(backgroundWRatio, backgroundHRatio));
            std::cout << "Background positions: " << backgroundTextures[i].getSize().x * backgroundWRatio << " " << backgroundTextures[i].getSize().y * backgroundHRatio << std::endl;
            if (i % 2 != 0)
                backgroundPositions.push_back(sf::Vector2f(backgroundTextures[i].getSize().x * backgroundWRatio, 0.0f));
            else
                backgroundPositions.push_back(sf::Vector2f(0.0f, 0.0f));
        }

    }

    void BackgroundComponent::update(float deltaTime, const sf::Vector2i& screenSize)
    {
        // Update the background positions based on their speeds and deltaTime
        for (int i = 0; i < backgroundLayers.size(); ++i)
        {
            backgroundPositions[i].x -= backgroundSpeeds[i] * deltaTime;
            // If the background has moved off the screen, reset its position to the right of the screen following the last background
            if (backgroundPositions[i].x <= (backgroundLayers[i]->getTexture().getSize().x * backgroundLayers[i]->getScale().x * -1.0f))
            {
                // Set the background position to the right of the last background, minux 0.5% to avoid a gap
                std::cout << "Resetting background " << i << " position.x " << backgroundLayers[i]->getTexture().getSize().x * backgroundLayers[i]->getScale().x - screenSize.x * 0.01f << std::endl;
                backgroundPositions[i].x = backgroundLayers[i]->getTexture().getSize().x * backgroundLayers[i]->getScale().x - screenSize.x * (0.005f * backgroundLayers[i]->getTexture().getSize().x / 900.0f);
            }
            backgroundLayers[i]->setPosition(backgroundPositions[i]);
            
        }
    }

    void BackgroundComponent::draw(sf::RenderWindow& window)
    {
        // Draw the background layers
        for (const auto& backgroundLayer : backgroundLayers)
        {
            window.draw(*backgroundLayer);
        }
    }
}
