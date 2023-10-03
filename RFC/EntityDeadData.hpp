/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ENTITYDeadData
*/

#ifndef ENTITYDEADDATA_HPP_
#define ENTITYDEADDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client when an entity is dead
             * @ref RFC::PacketType::ENTITY_DEAD
             * @see RFC::Packet
             */
            struct EntityDeadData {
                int id;
                bool isDead;
            };
        }
    }
}

#endif /* !ENTITYDEADDATA_HPP_ */
