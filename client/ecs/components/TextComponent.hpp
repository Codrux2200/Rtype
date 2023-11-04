/*
** TextComponent.hpp for client in /home/saad/Rtype/client/ecs/components
**
** Made by Saad Berrada
** Login   <saad.berrada@epitech.eu>
**
** Started on  Wed Oct 25 13:22:37 2023 Saad Berrada
** Last update Thu Oct 25 15:22:03 2023 Saad Berrada
*/

#ifndef TEXTCOMPONENT_HPP_
# define TEXTCOMPONENT_HPP_
#include <string>
#include <SFML/Graphics.hpp>
#include "AComponent.hpp"

namespace ECS{
    class TextComponent : public AComponent{
        public:
            TextComponent(std::string text);
            ~TextComponent();
            void setText(std::string text);
            sf::Text getText();
            std::string getString();
            std::shared_ptr<IComponent> clone() const override;
            void setColor(sf::Color color);
            void setFont(sf::Font);
            void setPosition(int x, int y);
        protected:
            sf::Color _color;
            sf::Font _font;
            sf::Text _text;
            std::string _string;
        private:
    };
}

#endif /* !TEXTCOMPONENT_HPP_ */
