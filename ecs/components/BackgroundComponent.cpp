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

        backgroundSpeeds = {0.0001f, 0.0002f, 0.0003f, 0.0004f, 0.0005f, 0.0006f};
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

void BackgroundComponent::update(float deltaTime, const sf::Vector2u& screenSize) {
    for (size_t i = 0; i < backgroundLayers.size(); ++i) {
        backgroundPositions[i].x -= backgroundSpeeds[i] * deltaTime;
        if (backgroundPositions[i].x + backgroundLayers[i]->getGlobalBounds().width <= 0.f) {
            // Reset the background layer to the right of the screen
            backgroundPositions[i].x = screenSize.x;
        }

        backgroundLayers[i]->setPosition(backgroundPositions[i]);
    }

    foregroundPosition.x -= foregroundSpeed * deltaTime;
    if (foregroundPosition.x + foreground->getGlobalBounds().width <= 0.f) {
        // Reset the foreground layer to the right of the screen
        foregroundPosition.x = screenSize.x;
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
