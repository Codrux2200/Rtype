/*
** EPITECH PROJECT, 2023
** RType
** File description:
** BeginData
*/

#pragma once

namespace RFC {
    namespace data {
        /**
         * @brief The data of type BeginData
         */
        struct BeginData {
            public:
                /** The number of players */
                int nbPlayers;

                /** The names of the players */
                char names[4][20];
        };
    } // namespace data
} // namespace RFC
