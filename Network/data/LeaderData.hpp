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
                 * @brief The id of the player that is the leader.
                 */
                char leaderId;
        };
    }
} // namespace Network::data
