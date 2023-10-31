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
        struct EntitySpawnData {
            public:
                int id;
                char type;
                int x;
                int y;
                float vx;
                float vy;
        };
    }
} // namespace Network::data
