/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EndData
*/

#ifndef ENDDATA_HPP_
#define ENDDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief the data for sharing end of game
             * to be used with @ref RFC::PacketType::END
             * @see RFC::Packet
             */
            class EndData {
                public:
                    bool end;
            };
        }
    }
}

#endif /* !ENDDATA_HPP_ */
