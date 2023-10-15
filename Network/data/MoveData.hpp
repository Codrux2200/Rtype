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
                char id;
                int x;
                int y;
        };
    }
} // namespace Network::data
