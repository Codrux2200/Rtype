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
    /**
     * @brief Text Component
     */
    class TextComponent : public AComponent{
        public:
            /**
             * @brief Construct a new Text Component object
             * 
             * @param text the text
             */
            TextComponent(std::string text);
            ~TextComponent();
            
            /**
             * @brief Set the text
             * 
             * @param text the text
             */
            void setText(std::string text);
            /**
             * @brief Get the text
             * 
             * @return sf::Text the text
             */
            sf::Text getText();
<<<<<<< HEAD
            std::string getString();
=======
            /**
             * @brief Clone the component
             * 
             * @return std::shared_ptr<IComponent> the component
             */
>>>>>>> origin/dev
            std::shared_ptr<IComponent> clone() const override;
            /**
             * @brief Set the Color object
             * 
             * @param color the color
             */
            void setColor(sf::Color color);
            /**
             * @brief Set the Font object
             * 
             * @param font the font
             */
            void setFont(sf::Font);
            /**
             * @brief Set the Position object
             * 
             * @param x the x position
             * @param y the y position
             */
            void setPosition(int x, int y);
        
        protected:
            /**
             * @brief the color
             * 
             */
            sf::Color _color;
            /**
             * @brief the font
             * 
             */
            sf::Font _font;
            /**
             * @brief the position
             * 
             */
            sf::Text _text;
            /**
             * @brief the string
             * 
             */
            std::string _string;
        private:
    };
}

#endif /* !TEXTCOMPONENT_HPP_ */
