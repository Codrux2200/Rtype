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
#include "Entity.hpp"

namespace ECS {
    using eventCallback = std::function<void(Network::PacketManager &, std::vector<Network::Packet> &, ECS::Entity &)>;
    class EventComponent : public AComponent {
        public:
            EventComponent(eventCallback callback);
            ~EventComponent() = default;

            std::shared_ptr<IComponent> clone() const override;

            std::vector<int> getValue() const override;

            void setValue(std::vector<int> values) override;

            virtual void execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt);

        protected:
            eventCallback _callback;
    };
}
