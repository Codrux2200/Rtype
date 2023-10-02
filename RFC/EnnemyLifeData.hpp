/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnnemyLifeData
*/

#ifndef ENNEMYLIFEDATA_HPP_
#define ENNEMYLIFEDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client to update the ennemy life.
             * to be used see @ref RFC::PacketType::ENNEMY_LIFE
             * @see RFC::Packet
             */
            struct EnnemyLifeData {
                int id;
                int life;
            };
        }
    }
}
#endif /* !ENNEMYLIFEDATA_HPP_ */
