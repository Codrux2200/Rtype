/*
** EPITECH PROJECT, 2023
** RType
** File description:
** HubData
*/

#pragma once

namespace Network::data {
    extern "C"
    {
        /**
         * @brief The packet indicating a player disconnected.
         * Network::PacketType::DISCONNECT "DISCONNECT" calls.
         *
         * @see Network::Packet
         * @see Network::PacketType::CONNECT
         * @see Network::PacketType::DISCONNECT
         * @see Network::Packet::connectData
         * @see Network::Packet::disconnectData
         */
        struct ConnectData {
            public:
                char id;
        };
    }
} // namespace Network::data
