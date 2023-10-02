/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HitData
*/

#ifndef HITDATA_HPP_
#define HITDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent when a player is hit or hit a target.
             * to be used see @ref RFC::PacketType::HIT
             * @see RFC::Packet
             */
            struct HitData {
                int id;
                int damage;
            };
        }
    }
}


#endif /* !HITDATA_HPP_ */
