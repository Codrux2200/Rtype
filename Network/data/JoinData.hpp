/*
** EPITECH PROJECT, 2023
** RType
** File description:
** JoinData
*/

#pragma once

#define NAME_LENGTH 7
namespace Network::data {
    extern "C"
    {
        struct JoinData {
            public:
                /** @brief Players connected including the host.
                 * The first player to connect will be the host.
                 * It will be the only one to be able to start the game.
                 * If it disconnects, the next player to connect will be the
                 * host
                 */
                char name[NAME_LENGTH];
        };
    }
} // namespace Network::data

