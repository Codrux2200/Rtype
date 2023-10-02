/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** DeadData
*/

#ifndef DEADDATA_HPP_
#define DEADDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
            @brief the data for sharing the death of a player to other player
            to be used with @ref RFC::PacketType::DEAD
            @see RFC::Packet
            */
            class DeadData {
                public:
                    bool IsAlive = 1;
            };
        }
    }
}

#endif /* !DEADDATA_HPP_ */
