/*
** EPITECH PROJECT, 2023
** RType
** File description:
** HubData
*/

#pragma once

#define NAME_LENGTH 7
#define MAX_PLAYERS 4

namespace Network::data {
    extern "C"
    {
        /**
         * @brief The data for sharing number of players connected with
         * their names. To be used with the @ref
         * Network::PacketType::CONNECT "CONNECT" and @ref
         * Network::PacketType::DISCONNECT "DISCONNECT" calls.
         *
         * @see Network::Packet
         * @see Network::Packet::connectData
         * @see Network::Packet::disconnectData
         *
         * @ref server_connect_sec "RFC: Connect"
         */
        struct ConnectData {
            public:
                char id;
                /** @brief Players connected.
                 * The first player to connect will be the leader.
                 * It will be the only one to be able to start the game.
                 * If it disconnects, the next player to connect will be the
                 * leader
                 */
                char players[MAX_PLAYERS][NAME_LENGTH];
        };
    }
} // namespace Network::data
