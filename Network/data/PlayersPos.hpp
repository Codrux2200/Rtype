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
                /**
                 * @brief The x position of the player.
                 */
                int x;
                /**
                 * @brief The y position of the player.
                 */
                int y;
        };
        struct PlayersPos {
                struct Position positions[4];
        };
    }
}
