#include "BackgroundComponent.hpp"

namespace ECS
{
    BackgroundComponent::BackgroundComponent()
    {
        // Initialize the component's properties here
        std::vector<std::string> backgroundPaths = {
            "1Background.png",
            "2Background.png",
            "3Background.png",
            "4Background.png",
            "5Background.png",
            "6Background.png"};

        backgroundSpeeds = {0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f};
        foregroundSpeed = 1.0f;

        for (const std::string &path : backgroundPaths)
        {
            sf::Texture texture;
            if (!texture.loadFromFile("assets/background/" + path))
            {
                throw std::runtime_error("Failed to load textures.");
            }
            backgroundTextures.push_back(texture);
        }

        foregroundTexture.loadFromFile("assets/background/foreground.png");

        for (const sf::Texture &texture : backgroundTextures)
        {
            backgroundLayers.push_back(std::make_unique<sf::Sprite>(texture));
        }

        for (size_t i = 0; i < backgroundTextures.size(); ++i)
        {
            backgroundPositions.emplace_back(0.f, 0.f - i * 600.f);
        }

        foreground = std::make_unique<sf::Sprite>(foregroundTexture);
        foregroundPosition = sf::Vector2f(0.f, 0.f);
    }

    void BackgroundComponent::update(float deltaTime)
    {
        for (size_t i = 0; i < backgroundLayers.size(); ++i)
        {
            backgroundPositions[i].x += backgroundSpeeds[i] * deltaTime; // Update the x-coordinate
            if (backgroundPositions[i].x >= 800.f)                       // Change 800.f to your window width
            {
                backgroundPositions[i].x = 0.f - i * 800.f; // Change 800.f to your window width
            }
            backgroundLayers[i]->setPosition(backgroundPositions[i]);
        }

        foregroundPosition.x += foregroundSpeed * deltaTime; // Update the x-coordinate
        if (foregroundPosition.x >= 800.f)                   // Change 800.f to your window width
        {
            foregroundPosition.x = 0.f; // Reset the x-coordinate
        }
        foreground->setPosition(foregroundPosition);
    }

    void BackgroundComponent::draw(sf::RenderWindow &window)
    {
        for (const std::unique_ptr<sf::Sprite> &layer : backgroundLayers)
        {
            window.draw(*layer);
        }
        window.draw(*foreground);
    }
}
