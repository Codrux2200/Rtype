/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ENTITYLifeData
*/

#ifndef ENTITYLIFEDATA_HPP_
#define ENTITYLIFEDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client to update the entity life.
             * to be used see @ref RFC::PacketType::ENTITY_LIFE
             * @see RFC::Packet
             */
            struct EntityLifeData {
                int id;
                int life;
            };
        }
    }
}
#endif /* !ENTITYLIFEDATA_HPP_ */
