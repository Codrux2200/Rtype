/*
** EPITECH PROJECT, 2023
** RType
** File description:
** StartData
*/

#pragma once

namespace Network::data {
    extern "C"
    {
        /**
         * @brief The data for sharing number of players connected with
         * their names. To be used with the @ref Network::PacketType::START
         * "START" call.
         * @see Network::Packet
         */
        struct StartData {
            public:
                short mapId;
        };
    }
} // namespace Network::data
