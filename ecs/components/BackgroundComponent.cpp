#include "BackgroundComponent.hpp"

ECS::BackgroundComponent::BackgroundComponent(const std::string& texturePath)
    : scrollSpeed(50.0f), backgroundSprite(backgroundTexture)  // Adjust the scroll speed as needed
{
    if (!backgroundTexture.loadFromFile(texturePath))
    {
        std::cerr << "Error loading background texture" << std::endl;
    }
    // Initialize the sprite with the texture
    backgroundSprite.setTexture(backgroundTexture);

    // Set the initial position
    backgroundSprite.setPosition(sf::Vector2f(0, 0));
}

void ECS::BackgroundComponent::update(float deltaTime)
{
    // Calculate the movement based on scroll speed and time
    float move = scrollSpeed * deltaTime;

    // Move the background
    backgroundSprite.move(sf::Vector2f(-move, 0));

    // Check if the background has gone off the screen
    if (backgroundSprite.getPosition().x + backgroundTexture.getSize().x < 0)
    {
        // Reset the background position to the right of the screen
        backgroundSprite.setPosition(sf::Vector2f(0, 0));
    }
}

void ECS::BackgroundComponent::draw(sf::RenderWindow& window)
{
    // Draw the background to the window
    window.draw(backgroundSprite);
}
