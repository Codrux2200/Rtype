/*
** EPITECH PROJECT, 2023
** RType
** File description:
** LeaderData
*/

#pragma once

namespace Network::data {
    extern "C"
    {
        struct LeaderData {
            public:
                /**
                 * @brief The id of the leader player.
                 * Only the leader player can start the game.
                 */
                int leaderId;
        };
    }
} // namespace Network::data
