/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EventComponent
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include "Connection.hpp"
#include "AComponent.hpp"

namespace ECS {
    using eventCallback = std::function<void(Network::PacketManager &, std::vector<Network::Packet> &)>;
    class EventComponent : public AComponent {
        public:
            EventComponent(eventCallback callback);
            ~EventComponent() = default;

            std::shared_ptr<IComponent> clone() const override;

            virtual void execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue);

        protected:
            eventCallback _callback;
    };
}
