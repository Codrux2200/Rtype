/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnnemyDeadData
*/

#ifndef ENNEMYDEADDATA_HPP_
#define ENNEMYDEADDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client when an ennemy is dead
             * @ref RFC::PacketType::ENNEMY_DEAD
             * @see RFC::Packet
             */
            struct EnnemyDeadData {
                int id;
                bool isDead;
            };
        }
    }
}

#endif /* !ENNEMYDEADDATA_HPP_ */
