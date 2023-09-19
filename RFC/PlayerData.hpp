/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerData
*/

#pragma once

namespace RFC {
    namespace data {
        /**
         * @brief The data of type PlayerData
         */
        struct PlayerData {
            public:
                /** Player id */
                int id;
                /** Player x position */
                int x;
                /** Player y position */
                int y;
        };
    } // namespace data
} // namespace RFC
