/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packet
*/

#pragma once

#include <ctime>
#include "ConnectData.hpp"
#include "JoinData.hpp"
#include "LeaderData.hpp"
#include "StartData.hpp"
#include "ConnectData.hpp"
#include "Status.hpp"

/**
 * @brief Network protocol
 */
namespace Network {
    extern "C"
    {
        /**
         * @brief Type of the packet
         * It determines the content of the packet, like the type of the data
         * and the size of the packet
         */
        enum PacketType {
            /**
             * @brief CONNECT packet
             * @ref Network::Packet::data "data" is a @ref
             * Network::data::HubData "HubData". The server sends a CONNECT
             * packet to all the clients when a new client is connected.
             *
             *
             * It will receive CONNECT from a client to accept a new
             * connection.
             *
             * If the server can't accept a new connection, the
             * server will send back a CONNECT packet with the status set to
             * @ref Network::Status::KO "KO" only to the sender, with an
             * appropriate message.
             */
            CONNECT,

            /**
             * @brief DISCONNECT packet
             * The data is stored on @red Network::Packet::disconnectData
             * "disconnectData" wich is of type @ref Network::data::HubData
             * "HubData". The server sends a DISCONNECT packet to all the
             * clients when a client is disconnected.
             *
             * It will receive DISCONNECT from a client to disconnect it.
             *
             * The data contained in the @ref Network::data::HubData "data" must
             * be the currently connected players without the disconnected one.
             */
            DISCONNECT,

            /**
             * @brief START packet
             * The data is stored on @ref Network::Packet::startData "startData"
             * wich is of type @ref Network::data::StartData "StartData". The
             * server sends a START packet to all the clients when the host
             * starts the game.
             *
             * It will receive START from a client to start the game.
             *
             * The data contained in the @ref Network::data::StartData "data"
             * must be the map to be used.
             *
             * It have to be sent by the host to the server. Then, the server
             * will send it back to all the players to tell them that the game
             * is about to start.
             */
            START,

            /**
             * @brief Sent by server to all the clients when a player is dead.
             *
             */
            DEAD,

            /**
             * @brief Sent by client to try to join a game.
             *
             */
            JOIN,
            MOVE,
            SHOOT,
            HIT,
            SCORE,
            ENEMY_SPAWN,
            ENEMY_DEAD,
            ENEMY_MOVE,
            ENEMY_SHOOT,
            ENEMY_LIFE,
            MAP,
            END,
            LEADER,
        };

        /**
         * @brief A Packet is the structure sent by both client and server.
         * It contains a @ref Network::Status "Status", the @ref
         * Network::PacketType "type" of the packet and the associated @ref
         * Network::Packet::data "data".
         */
        struct Packet {
            public:
                PacketType type; ///< The type of the packet

                union {
                        struct data::ConnectData
                        connectData; ///< The data of the CONNECT packet
                        struct data::ConnectData
                        disconnectData; ///< The data of the DISCONNECT packet
                        struct data::StartData
                        startData; ///< The data of the START packet
                        struct data::JoinData
                        joinData; ///< The data of the JOIN packet
                        struct data::LeaderData
                        leaderData; ///< The data of the LEADER packet
                };
        };
    }
} // namespace Network
