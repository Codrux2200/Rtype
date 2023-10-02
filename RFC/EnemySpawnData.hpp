/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemySpawnData
*/

#ifndef ENEMYSPAWNDATA_HPP_
#define ENEMYSPAWNDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client to spawn an enemy.
             * to be used see @ref RFC::PacketType::ENEMY_SPAWN
             * @see RFC::Packet
             */
            struct EnemySpawnData {
                int id;
                int x;
                int y;
                int direction;
                int type;
            };
        }
    }
}

#endif /* !ENEMYSPAWNDATA_HPP_ */
