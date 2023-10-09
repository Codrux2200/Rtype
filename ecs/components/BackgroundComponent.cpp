#include "BackgroundComponent.hpp"

namespace ECS
{
    BackgroundComponent::BackgroundComponent()
    {
        // Initialize the component's properties here
        std::vector<std::string> backgroundPaths = {
            "6Background.png",
            "5Background.png",
            "4Background.png",
            "3Background.png",
            "2Background.png",
            "1Background.png"};

        backgroundSpeeds = {0.0f, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006};
        foregroundSpeed = 0.0f;

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
            backgroundPositions.emplace_back(0.f, 0.f - i * 6.f);
        }

        foreground = std::make_unique<sf::Sprite>(foregroundTexture);
        foregroundPosition = sf::Vector2f(0.f, 0.f);
    }

void BackgroundComponent::update(float deltaTime, const sf::Vector2u& screenSize) {
    for (size_t i = 0; i < backgroundLayers.size(); ++i) {
        if (deltaTime < 10000.0f)
            backgroundPositions[i].x -= backgroundSpeeds[i] * deltaTime;
        else
            backgroundPositions[i].x -= backgroundSpeeds[i] * 10000.0f;
        if (backgroundPositions[i].x + backgroundLayers[i]->getGlobalBounds().width <= 0.f) {
            // Reset the background layer to the right of the screen
            backgroundPositions[i].x = screenSize.x;
        }

        backgroundLayers[i]->setPosition(backgroundPositions[i]);
    }

    foregroundPosition.x -= foregroundSpeed * deltaTime;
    if (foregroundPosition.x + foreground->getGlobalBounds().width <= 0.f) {
        // Reset the foreground layer to the right of the screen
        //place foreground to bottom
        foregroundPosition.y = screenSize.y - foreground->getGlobalBounds().height;
        foregroundPosition.x = screenSize.x;
    }

    foreground->setPosition(foregroundPosition);
}



void BackgroundComponent::draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < backgroundLayers.size(); ++i)
    {
        backgroundLayers[i]->setTexture(backgroundTextures[i]); // Set the texture for each background layer
        backgroundLayers[i]->setPosition(backgroundPositions[i]); // Set the position for each background layer

        // Calculate the scale factor
        sf::Vector2f scale(
            static_cast<float>(window.getSize().x) / backgroundLayers[i]->getLocalBounds().width,
            static_cast<float>(window.getSize().y) / backgroundLayers[i]->getLocalBounds().height);

        // Set the scale
        backgroundLayers[i]->setScale(scale);
        
        window.draw(*backgroundLayers[i]); // Draw each background layer
    }
    foreground->setTexture(foregroundTexture); // Set the texture for the foreground
    foreground->setPosition(foregroundPosition); 
    //resize foreground to fit the screen
    sf::Vector2f scale(
        static_cast<float>(window.getSize().x) / foreground->getLocalBounds().width,
        static_cast<float>(window.getSize().y) / foreground->getLocalBounds().height);
    //set foreground to bottom of the screen
    window.draw(*foreground); // Draw the foreground
}



}
