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

namespace ECS {
    using eventCallback = std::function<void(Network::PacketManager &, std::vector<Network::Packet> &)>;
    class ClickComponent : public AComponent {
        public:
            ClickComponent(sf::Rect<int> rect, eventCallback callback);
            ~ClickComponent() = default;

            std::vector<int> getValue() const final;
            void setValue(std::vector<int> values) final;

            std::shared_ptr<IComponent> clone() const override;

            void onClick(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue);

            sf::Rect<int> getRect() const;


        private:
            sf::Rect<int> _rect;
            eventCallback _callback;
    };
}
