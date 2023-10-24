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
#include "MoveData.hpp"
#include "PacketType.hpp"
#include "StartData.hpp"
#include "PlayersPos.hpp"

/**
 * @brief Network protocol
 */

#define MILLISECONDS_TICKS 20

namespace Network {
    extern "C"
    {
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
                        struct data::MoveData
                        moveData; ///< The data of the MOVE packet
                        struct data::PlayersPos playersPos;
                };
        };
    }
} // namespace Network
