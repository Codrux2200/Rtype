/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ClickComponent
*/

#include <iostream>
#include "ClickComponent.hpp"

ECS::ClickComponent::ClickComponent(sf::Rect<int> rect, ECS::eventCallback callback, sf::RenderWindow &window) : ECS::EventComponent(callback), _rect(rect), _window(window)
{
}

std::vector<int> ECS::ClickComponent::getValue() const
{
    std::vector<int> values;

    values.push_back(_rect.left);
    values.push_back(_rect.top);
    values.push_back(_rect.width);
    values.push_back(_rect.height);
    return values;
}

void ECS::ClickComponent::setValue(std::vector<int> values)
{
    if (values.size() != 4) {
        std::cerr << "Error: setValue in ClickComponent" << std::endl;
        return;
    }
    _rect.left = values[0];
    _rect.top = values[1];
    _rect.width = values[2];
    _rect.height = values[3];
}

std::shared_ptr<ECS::IComponent> ECS::ClickComponent::clone() const
{
    return std::make_shared<ClickComponent>(_rect, _callback, _window);
}

void ECS::ClickComponent::execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity)
{
    // Get mouse position in window
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_rect.contains(mousePos)) {
            _callback(packetManager, packetsQueue, entity);
        }
    }
}
