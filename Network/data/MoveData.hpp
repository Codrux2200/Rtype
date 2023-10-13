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
                short id;
                int x;
                int y;
                int z;
        };
    }
} // namespace Network::data
