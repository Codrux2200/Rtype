/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MapData
*/

#ifndef MAPDATA_HPP_
#define MAPDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief the data for sharing map data
             * to be used with @ref RFC::PacketType::MAP
             * @see RFC::Packet
            */
            struct MapData {
                int id;
                int x;
                int y;
                int width;
                int height;
                int type;
            };
        }
    }
}
#endif /* !MAPDATA_HPP_ */
