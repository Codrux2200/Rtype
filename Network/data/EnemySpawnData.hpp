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
        struct EnemySpawnData {
            public:
                int id;
                char type;
                int x;
                int y;
        };
    }
} // namespace Network::data
