/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ENTITYShootData
*/

#ifndef ENTITYSHOOTDATA_HPP_
#define ENTITYSHOOTDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client when an entity shoot
             * @ref RFC::PacketType::ENTITY_SHOOT
             * @see RFC::Packet
             */
            struct EntityShootData {
                int id;
                int x;
                int y;
            };
        }
    }
}

#endif /* !ENTITYSHOOTDATA_HPP_ */
