/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayersPos
*/

#pragma once

namespace Network::data {
    extern "C" {
        struct Position {
                int x;
                int y;
        };
        struct PlayersPos {
                struct Position positions[4];
        };
    }
}
