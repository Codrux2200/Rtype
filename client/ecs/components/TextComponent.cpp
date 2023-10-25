/*
** TextComponent.cpp for client in /home/saad/Rtype/client/ecs/components
**
** Made by Saad Berrada
** Login   <saad.berrada@epitech.eu>
**
** Started on  Wed Oct 25 13:21:52 2023 Saad Berrada
** Last update Thu Oct 25 15:25:53 2023 Saad Berrada
*/

#include "TextComponent.hpp"
#include <iostream>

namespace ECS{
    TextComponent::TextComponent(std::string text) : _Text(_Font)
    {
        if (!_Font.loadFromFile("assets/arial.ttf"))
            std::cout<<"error loading the font"<<std::endl;
        _Color = sf::Color::Red;
        _Text.setFont(_Font);
        _Text.setString(text);
        _Text.setFillColor(_Color);
        _String = text;
    }

    TextComponent::~TextComponent()
    {
    }
    std::shared_ptr<IComponent> TextComponent::clone() const
    {
    return std::make_shared<TextComponent>(_String);
    }

    void TextComponent::setText(std::string text){
        _Text.setString(text);
    }
    void TextComponent::setFont(sf::Font font){
        _Font = font;
        _Text.setFont(_Font); 
    }
    void TextComponent::setColor(sf::Color color){
        _Color = color;
        _Text.setFillColor(color);
    }

    sf::Text TextComponent::getText(){
        return _Text;
    }

    void TextComponent::setPosition(int x, int y){
        sf::Vector2<float> vecteur(x, y);
        _Text.setPosition(vecteur);
    }
}

