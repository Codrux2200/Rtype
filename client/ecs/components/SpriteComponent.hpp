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
            /**
             * @brief Construct a new Sprite Component object
             *
             * @param texture the texture
             * @param rect the rect
             * @param maxIterations the max iterations
             * @param animSpeed the animation speed
             * @param spriteGrid the sprite grid
             */
            SpriteComponent(std::shared_ptr<sf::Texture> texture, sf::Rect<int> rect, int maxIterations = 0, float animSpeed = 10, sf::Vector2i spriteGrid = sf::Vector2i(1, 1), bool isAnimated = false);
            ~SpriteComponent();
            /**
             * @brief Set the Texture object to the sprite
             *
             * @param texture the texture
             */
            void setTexture(std::shared_ptr<sf::Texture> &texture);
            /**
             * @brief Update the animation of the sprite
             *
             * @param dt the delta time
             */
            void updateAnimation(float dt);

            /**
             * @brief Get the Sprite object
             *
             * @return sf::Sprite the sprite
             */
            const sf::Sprite &getSprite() const;
            /**
             * @brief Get the Rect object
             *
             * @return sf::Rect<int> the rect
             */
            sf::Rect<int> &getRect();

            /**
             * @brief Set the next animation
            */
            void nextAnimation();

            /**
             * @brief Set the animation step
             *
             * @param step the step
            */
            void setAnimationStep(int step);

            /**
             * @brief The rect
            */
            sf::Rect<int> _rect;

            /**
             * @brief clone the component
             *
             * @return std::shared_ptr<IComponent> the cloned component
             */
            [[nodiscard]]
            std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief the max iterations
            */
            int maxIterations;
            /**
             * @brief the animation speed
            */
            float animSpeed;
            /**
             * @brief the sprite grid
            */
            sf::Vector2i spriteGrid;
            /**
             * @brief the animation step
            */
            int animStep = 0;

            bool isAnimated = false;

        private:
            /**
             * @brief the texture
             */
            std::shared_ptr<sf::Texture> _texture;
            /**
             * @brief the sprite
             */
            sf::Sprite _sprite;
            /**
             * @brief the _timer
            */
            float _timer = 0;
    };
}

