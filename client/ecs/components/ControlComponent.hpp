/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ControlComponent
*/

#pragma once

#include <string>
#include <memory>
#include "EventComponent.hpp"

namespace ECS {
    /**
     * @brief Player component
     */
    class ControlComponent : public EventComponent {
        public:
            ControlComponent(eventCallback callback);

            std::vector<int> getValue() const final;

            void setValue(std::vector<int> values) final;

            std::shared_ptr<IComponent> clone() const override;

            void execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt) final override;

        private:
            int _speed = 400;

    };
}
