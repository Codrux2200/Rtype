#ifndef BACKGROUNDCOMPONENT_HPP_
#define BACKGROUNDCOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

namespace ECS {
    class BackgroundComponent {
    public:
        BackgroundComponent(const std::string& texturePath);

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        float scrollSpeed;
    };
}

#endif /* !BACKGROUNDCOMPONENT_HPP_ */
