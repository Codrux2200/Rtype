#ifndef BACKGROUND_COMPONENT_HPP
#define BACKGROUND_COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "../AComponent.hpp"
#include <vector>

namespace ECS {
    class BackgroundComponent {
    public:
        BackgroundComponent(
            const std::vector<std::string>& backgroundPaths,
            const std::string& foregroundPath,
            const std::vector<float>& backgroundSpeeds,
            float foregroundSpeed
        );

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

    private:
        std::vector<sf::Texture> backgroundTextures;
        sf::Texture foregroundTexture;

        std::vector<sf::Sprite> backgroundLayers;
        sf::Sprite foreground;

        std::vector<float> backgroundSpeeds;
        float foregroundSpeed;

        std::vector<sf::Vector2f> backgroundPositions;
        sf::Vector2f foregroundPosition;
    };
}


#endif // BACKGROUND_COMPONENT_HPP
