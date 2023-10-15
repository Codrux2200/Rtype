/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** playerComponent
*/

#pragma once

#include <string>
#include <memory>
#include "EventComponent.hpp"

namespace ECS {
    /**
     * @brief Player component
     */
    class PlayerComponent : public EventComponent {
    public:
        /**
         * @brief Construct a new player Component object
         *
         * @param uid
         * @param spritePath The path to the player sprite image
         */
        PlayerComponent(eventCallback callback);

        std::vector<int> getValue() const final;

        void setValue(std::vector<int> values) final;

        std::shared_ptr<IComponent> clone() const override;

        void execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, Entity &entity) final override;

    };
}
