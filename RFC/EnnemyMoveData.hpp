/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnnemyMoveData
*/

#ifndef ENNEMYMOVEDATA_HPP_
#define ENNEMYMOVEDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client when an ennemy is moving
             * @ref RFC::PacketType::ENNEMY_MOVE
             * @see RFC::Packet
             */
            struct EnnemyMoveData {
                int id;
                int x;
                int y;
            };
        }
    }
}
#endif /* !ENNEMYMOVEDATA_HPP_ */
