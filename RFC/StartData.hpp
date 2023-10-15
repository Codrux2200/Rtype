/*
** EPITECH PROJECT, 2023
** RType
** File description:
** StartData
*/

#pragma once

namespace RFC {
    namespace data {
        extern "C"
        {
            /**
             * @brief The data for sharing number of players connected with
             * their names. To be used with the @ref RFC::PacketType::START
             * "START" call.
             * @see RFC::Packet
             */
            struct StartData {
                public:
                    short mapId;
            };
        }
    } // namespace data
} // namespace RFC
