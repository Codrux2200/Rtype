/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ScoreData
*/

#ifndef SCOREDATA_HPP_
#define SCOREDATA_HPP_

namespace RFC {
    namespace data {
        extern "C" {
            /**
             * @brief data sent to the client to update the score.
             * to be used see @ref RFC::PacketType::SCORE
             * @see RFC::Packet
             */
            struct ScoreData {
                int id;
                int score;
            };
        }
    }
}
#endif /* !SCOREDATA_HPP_ */
