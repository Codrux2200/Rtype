/*
** EPITECH PROJECT, 2023
** RType
** File description:
** MoveData
*/

#pragma once

namespace Network::data {
    extern "C"
    {
        struct MoveData {
            public:
                /**
                 * @brief The id of the player that moved.
                 */
                char id;
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
