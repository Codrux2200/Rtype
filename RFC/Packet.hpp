/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packet
*/

#pragma once

#include "BeginData.hpp"
#include "PlayerData.hpp"

/**
 * @brief RFC protocol
 */
namespace RFC {

    /**
     * @brief Status code of the packet
     */
    enum Status {

        /** The packet is valid, no error */
        OK = 200,

        /** The packet is invalid, the data is invalid */
        UNKNOW = 400,

    };

    /**
     * @brief Type of the packet
     * It can determine the content of the packet, like the type of the data and
     * the size of the packet
     */
    enum PacketType {
        BEGIN, /** The game starts, the associated data is of type BeginData */
        PLAYER_MOVE, /** The player moves, the associated data is of type
                      * PlayerMoveData */
        END, /** The game ends, the associated data is of type EndData */
    };

    /**
     * @brief A Packet is the structure sent by both client and server.
     * It contains the status of the packet, the type of the packet and the
     * associated data.
     */
    struct Packet {
        public:
            /** The status of the packet */
            Status status;

            /** The type of the packet */
            PacketType type;

            /** The associated data */
            union {
                    /** Data to be recovered if the packet is of type
                     * PlayerMoveData */
                    RFC::data::PlayerData movePlayerData;

                    /** Data to be recovered if the packet is of type
                     * BeginData */
                    RFC::data::BeginData beginData;
            } data;
    };
}; // namespace RFC
