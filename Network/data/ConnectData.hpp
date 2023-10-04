/*
** EPITECH PROJECT, 2023
** RType
** File description:
** HubData
*/

#pragma once

#define NAME_LENGTH 7
#define MAX_PLAYERS 4

namespace Network {
    namespace data {
        extern "C"
        {
            /**
             * @brief The data for sharing number of players connected with
             * their names. To be used with the @ref
             * Network::PacketType::CONNECT "CONNECT" and @ref
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
                    /** @brief Players connected including the host.
                     * The first player to connect will be the host.
                     * It will be the only one to be able to start the game.
                     * If it disconnects, the next player to connect will be the
                     * host
                     */
                    char players[MAX_PLAYERS][NAME_LENGTH];
            };
        }
    } // namespace data
} // namespace Network
