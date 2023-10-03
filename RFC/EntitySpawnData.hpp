/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ENTITYSpawnData
*/

#ifndef ENTITYSPAWNDATA_HPP_
#define ENTITYSPAWNDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client to spawn an entity.
             * to be used see @ref RFC::PacketType::ENTITY_SPAWN
             * @see RFC::Packet
             */
            struct EntitySpawnData {
                int id;
                int x;
                int y;
                int direction;
                int type;
            };
        }
    }
}

#endif /* !ENTITYSPAWNDATA_HPP_ */
