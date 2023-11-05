/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ClickComponent
*/

#include "ClickComponent.hpp"
#include <iostream>
#include "ScaleComponent.hpp"
#include "SpriteComponent.hpp"

ECS::ClickComponent::ClickComponent(sf::Rect<int> rect, ECS::eventCallback callback, sf::RenderWindow &window) : ECS::AEventComponent(), _rect(rect), _window(window), _callback(callback)
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
bool ECS::ClickComponent::execute(
std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
{
    // Get mouse position in window
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
    if (_callback != nullptr && _rect.contains(mousePos)){
//        std::shared_ptr<ECS::ScaleComponent> scale = entity.getComponent<ECS::ScaleComponent>();
//        std::vector<float> size = scale->getFloatValue();
//        scale->setFloatValue(1.5, 1.5);
    } else {
//        std::shared_ptr<ECS::ScaleComponent> scale = entity.getComponent<ECS::ScaleComponent>();
//        std::vector<float> size = scale->getFloatValue();
//        scale->setFloatValue(1.0, 1.0);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _callback != nullptr && _rect.contains(mousePos)) {
        return _callback(packetsQueue, entity);
    }
    return false;
}

