/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief set texture for entity and player
     *
    */
    class SpriteComponent : public AComponent {
        public:
            SpriteComponent(sf::Texture texture, sf::Rect<int> rect);
            ~SpriteComponent();
            void setTexture(sf::Texture &texture);
            void setMaxIteration(sf::Vector2i max_iteration);
            void moveRect();

            const sf::Sprite &getSprite() const;
            sf::Rect<int> &getRect();
            sf::Vector2i getIterations() const { return _iterations; }

            std::shared_ptr<IComponent> clone() const override;

        private:
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Rect<int> _rect;
            sf::Vector2i _maxIterations;
            sf::Vector2i _iterations;
    };
}

#endif /* !SPRITECOMPONENT_HPP_ */
