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
                /**
                 * @brief The id of the player that disconnected.
                 */
                char id;
        };
    }
} // namespace Network::data
