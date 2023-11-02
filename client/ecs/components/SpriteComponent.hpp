/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief set texture for entity and player
     *
    */
    class SpriteComponent : public AComponent {
        public:
            SpriteComponent(sf::Texture texture, sf::Rect<int> rect, int maxIterations = 0, float animSpeed = 10, sf::Vector2i spriteGrid = sf::Vector2i(1, 1));
            ~SpriteComponent();
            void setTexture(sf::Texture &texture);
            void updateAnimation(float dt);

            const sf::Sprite getSprite() const;
            sf::Rect<int> &getRect();

            void nextAnimation();

            void setAnimationStep(int step);

            sf::Rect<int> _rect;

            std::shared_ptr<IComponent> clone() const override;

            int maxIterations;
            float animSpeed;
            sf::Vector2i spriteGrid;
            int animStep = 0;

            bool isAnimated = false;

        private:
            sf::Texture _texture;
            sf::Sprite _sprite;
            float _timer = 0;
    };
}

