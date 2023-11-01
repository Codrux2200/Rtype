/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PacketType
*/

#pragma once

namespace Network::data {
    extern "C"
    {
        /**
         *
         */
        struct EntitySpawnData {
            public:
                /**
                 * @brief The id of the player that moved.
                 */
                int id;
                /**
                 * @brief The type of the entity.
                 */
                char type;
                /**
                 * @brief The x position of the player.
                 */
                int x;
                /**
                 * @brief The y position of the player.
                 */
                int y;
        };
    }
} // namespace Network::data
