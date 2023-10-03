/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ENTITYMoveData
*/

#ifndef ENTITYMOVEDATA_HPP_
#define ENTITYMOVEDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client when an entity is moving
             * @ref RFC::PacketType::ENTITY_MOVE
             * @see RFC::Packet
             */
            struct EntityMoveData {
                int id;
                int x;
                int y;
            };
        }
    }
}
#endif /* !ENTITYMOVEDATA_HPP_ */
