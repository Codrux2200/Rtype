/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SpriteComponent
*/

#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include "../AComponent.hpp"
#include <SFML/Graphics.hpp>

namespace ECS {
    /**
     * @brief set texture for entity and player
     * 
    */
    class SpriteComponent : public AComponent{
        public:
            SpriteComponent();
            ~SpriteComponent();
            void setTexture(sf::Texture texture);
            const sf::Sprite &getSprite() const;

        private:
            sf::Sprite _sprite;
    };
}

#endif /* !SPRITECOMPONENT_HPP_ */
