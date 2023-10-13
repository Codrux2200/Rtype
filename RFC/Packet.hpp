/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packet
*/

#pragma once

#include <ctime>
#include "HubData.hpp"
#include "StartData.hpp"
#include "Status.hpp"

/**
 * @brief RFC protocol
 */
namespace RFC {
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
             * @ref RFC::Packet::data "data" is a @ref RFC::data::HubData
             * "HubData". The server sends a CONNECT packet to all the clients
             * when a new client is connected.
             *
             *
             * It will receive CONNECT from a client to accept a new
             * connection.
             *
             * If the server can't accept a new connection, the
             * server will send back a CONNECT packet with the status set to
             * @ref RFC::Status::KO "KO" only to the sender, with an appropriate
             * message.
             */
            CONNECT,

            /**
             * @brief DISCONNECT packet
             * The data is stored on @red RFC::Packet::disconnectData
             * "disconnectData" wich is of type @ref RFC::data::HubData
             * "HubData". The server sends a DISCONNECT packet to all the
             * clients when a client is disconnected.
             *
             * It will receive DISCONNECT from a client to disconnect it.
             *
             * The data contained in the @ref RFC::data::HubData "data" must be
             * the currently connected players without the disconnected one.
             */
            DISCONNECT,

            /**
             * @brief START packet
             * The data is stored on @ref RFC::Packet::startData "startData"
             * wich is of type @ref RFC::data::StartData "StartData". The server
             * sends a START packet to all the clients when the host starts the
             * game.
             *
             * It will receive START from a client to start the game.
             *
             * The data contained in the @ref RFC::data::StartData "data" must
             * be the map to be used.
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
            MOVE,
            SHOOT,
            HIT,
            SCORE,
            ENTITY_SPAWN,
            ENTITY_DEAD,
            ENTITY_MOVE,
            ENTITY_SHOOT,
            ENTITY_LIFE,
            MAP,
            END,
        };

        /**
         * @brief A Packet is the structure sent by both client and server.
         * It contains a @ref RFC::Status "Status", the @ref RFC::PacketType
         * "type" of the packet and the associated @ref RFC::Packet::data
         * "data".
         */
        struct Packet {
            public:
                long int id;       ///< growing ID
                int sequence;      ///< sequence number / tick number
                short replication; ///< what replication is this
                long timestamp;    ///< timestamp of the packet
                Status status;     ///< The status of the packet
                PacketType type;   ///< The type of the packet
                char message[256]; ///< The message of the packet

                union {
                        struct data::HubData
                        connectData; ///< The data of the CONNECT packet
                        struct data::HubData
                        disconnectData; ///< The data of the DISCONNECT packet
                        struct data::StartData
                        startData; ///< The data of the START packet
                };
        };
    }
} // namespace RFC
