/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ShootData
*/

#ifndef SHOOTDATA_HPP_
#define SHOOTDATA_HPP_

namespace RFC { 
    namespace data {
        extern "C" {
            /**
             * @brief Data send by the client to the server to shoot.
             * to be used see @ref RFC::PacketType::SHOOT
             * @see RFC::Packet
             * 
            */
            struct ShootData {
                int id;
                int x;
                int y;
                int direction;
            };
        }
    }
}

#endif /* !SHOOTDATA_HPP_ */
