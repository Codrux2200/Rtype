/*
** EPITECH PROJECT, 2023
** RType
** File description:
** HubData
*/

#pragma once

namespace Network::data {
    extern "C"
    {

        enum DeathReason {
            PLAYER_BULLET,
            ENEMY_BULLET,
            ENEMY,
            OUT_OF_BOUNDS,
            UNKNOWN,
            ALIVE
        };

        struct DeadData {
            public:
                int id;
                DeathReason reason;
        };
    }
} // namespace Network::data
