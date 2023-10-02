/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MoveData
*/

#ifndef MOVEDATA_HPP_
#define MOVEDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
            @brief the data for sharing players movement 
            to be used with @ref RFC::PacketType::MOVE
            @see RFC::Packet
            */
            class MoveData {
                public:
                    int id;
                    int x;
                    int y;
            };
        }
    }
}
#endif /* !MOVEDATA_HPP_ */
