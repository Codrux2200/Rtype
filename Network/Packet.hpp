/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packet
*/

#pragma once

#include <ctime>
#include "ConnectData.hpp"
#include "DeadData.hpp"
#include "EntitySpawnData.hpp"
#include "JoinData.hpp"
#include "LeaderData.hpp"
#include "PacketType.hpp"
#include "PlayersPos.hpp"
#include "StartData.hpp"
#include "BossStateData.hpp"
#include "ScoreData.hpp"
/**
 * @brief Network protocol
 */

#define TICK_TIME_MILLIS 20

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
                /**
                 * @brief The type of the packet to be sent (or then received)
                 */
                PacketType type;

                /**
                 * @brief A union is used so any of the payload types can be sent in the same form
                 */
                union {
                    /**
                     * @brief The packet connectData is of type @ref data::ConnectData
                     */
                    struct data::ConnectData
                    connectData;
                    /**
                     * @brief The packet disconnectData is of type @ref data::ConnectData
                     */
                    struct data::ConnectData
                    disconnectData;
                    /**
                     * @brief The packet startData is of type @ref data::StartData
                     */
                    struct data::StartData
                    startData;
                    /**
                     * @brief The packet joinData is of type @ref data::JoinData
                     */
                    struct data::JoinData
                    joinData;
                    struct data::ScoreData scoreData;
                    /**
                     * @brief The packet leaderData is of type @ref data::LeaderData
                     */
                    struct data::LeaderData
                    leaderData;
                    /**
                     * @brief The packet playersPos is of type @ref data::PlayersPos
                     */
                    struct data::PlayersPos playersPos;
                    /**
                     * @brief The packet deadData is of type @ref data::DeadData
                     */
                    struct data::DeadData deadData;
                    /**
                     * @brief The packet entitySpawnData is of type @ref data::EntitySpawnData
                     */
                    struct data::EntitySpawnData entitySpawnData;
                        struct data::BossStateData bossStateData;
                };
        };
    }
} // namespace Network
