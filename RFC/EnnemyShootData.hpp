/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnnemyShootData
*/

#ifndef ENNEMYSHOOTDATA_HPP_
#define ENNEMYSHOOTDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client when an ennemy shoot
             * @ref RFC::PacketType::ENNEMY_SHOOT
             * @see RFC::Packet
             */
            struct EnnemyShootData {
                int id;
                int x;
                int y;
            };
        }
    }
}

#endif /* !ENNEMYSHOOTDATA_HPP_ */
