/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ClickComponent
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include "Connection.hpp"
#include "AComponent.hpp"
#include "PacketManager.hpp"
#include "EventComponent.hpp"

namespace ECS {
    class ClickComponent : public EventComponent {
        public:
            ClickComponent(sf::Rect<int> rect, eventCallback callback, sf::RenderWindow &window);

            std::vector<int> getValue() const final;
            void setValue(std::vector<int> values) final;

            std::shared_ptr<IComponent> clone() const override;

            void execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue) final override;

        private:
            sf::Rect<int> _rect;
            sf::RenderWindow &_window;
    };
}
