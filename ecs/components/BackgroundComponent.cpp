
#include "BackgroundComponent.hpp"

namespace ECS {
    BackgroundComponent::BackgroundComponent(
        const std::vector<std::string>& backgroundPaths,
        const std::string& foregroundPath,
        const std::vector<float>& backgroundSpeeds,
        float foregroundSpeed
    ) : backgroundSpeeds(backgroundSpeeds), foregroundSpeed(foregroundSpeed) {
        for (const std::string& path : backgroundPaths) {
            sf::Texture texture;
            if (!texture.loadFromFile("../../assets" + path)) {
                throw std::runtime_error("Failed to load textures.");
            }
            backgroundTextures.push_back(texture);
        }

        foregroundTexture.loadFromFile("../../assets/" + path);

        for (const sf::Texture& texture : backgroundTextures) {
            backgroundLayers.emplace_back(texture);
        }

        foreground.setTexture(foregroundTexture);

        for (size_t i = 0; i < backgroundTextures.size(); ++i) {
            backgroundPositions.emplace_back(0.f, 0.f - i * 600.f);
        }

        foregroundPosition = sf::Vector2f(0.f, 0.f);
    }

    void BackgroundComponent::update(float deltaTime) {
        for (size_t i = 0; i < backgroundPositions.size(); ++i) {
            backgroundPositions[i].y += backgroundSpeeds[i] * deltaTime;
            
            if (backgroundPositions[i].y >= 600) {
                backgroundPositions[i].y = -600.f;
            }
        }
        
        foregroundPosition.y += foregroundSpeed * deltaTime;

        if (foregroundPosition.y >= 600) {
            foregroundPosition.y = -600.f;
        }
    }

    void BackgroundComponent::draw(sf::RenderWindow& window) {
        for (const sf::Sprite& background : backgroundLayers) {
            window.draw(background);
        }
        window.draw(foreground);
    }
}