/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DisconnectData
*/

#pragma once


namespace Network::data {
    extern "C"
    {
        struct DisconnectData {
            public:
                /** @brief A player disconnected.
                 * id is the id of the disconnected player.
                 * used to notify every client of the disconnected player.
                 */
                char id;
        };
    }
} // namespace Network::data

