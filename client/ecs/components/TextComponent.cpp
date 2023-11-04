/*
** TextComponent.cpp for client in /home/saad/Rtype/client/ecs/components
**
** Made by Saad Berrada
** Login   <saad.berrada@epitech.eu>
**
** Started on  Wed Oct 25 13:21:52 2023 Saad Berrada
** Last update Sat Oct 27 15:14:11 2023 Saad Berrada
*/

#include "TextComponent.hpp"
#include <iostream>

namespace ECS{
    TextComponent::TextComponent(std::string text) : _text(_font)
    {
        if (!_font.loadFromFile("assets/arial.ttf"))
            std::cout<<"error loading the font"<<std::endl;
        _color = sf::Color::Red;
        _text.setFont(_font);
        _text.setString(text);
        _text.setFillColor(_color);
        _string = text;
    }

    TextComponent::~TextComponent()
    {
    }
    std::shared_ptr<IComponent> TextComponent::clone() const
    {
    return std::make_shared<TextComponent>(_string);
    }

    void TextComponent::setText(std::string text){
        _text.setString(text);
    }
    void TextComponent::setFont(sf::Font font){
        _font = font;
        _text.setFont(_font); 
    }
    void TextComponent::setColor(sf::Color color){
        _color = color;
        _text.setFillColor(color);
    }

    sf::Text TextComponent::getText(){
        return _text;
    }

    std::string TextComponent::getString(){
        return _text.getString();
    }

    void TextComponent::setPosition(int x, int y){
        sf::Vector2<float> vecteur(x, y);
        _text.setPosition(vecteur);
    }
}

