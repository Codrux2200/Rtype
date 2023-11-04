/*
** EPITECH PROJECT, 2023
** RType
** File description:
** BossStateData
*/

#pragma once

namespace Network::data {
    extern "C"
    {
        enum BossState {
            IDLE,           // DONE
            DASH,           // DONE
            COMING,         // DONE
            ATTACK_UP,      // DONE
            ATTACK_DOWN,    // DONE
            SHOOT,           // DONE
            MOVE
        };

        struct BossStateData {
            public:
                int id;
                int x;
                int y;
                int isUp;
                BossState state;
        };
    }
} // namespace Network::data
