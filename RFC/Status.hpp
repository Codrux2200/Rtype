/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Status
*/

#pragma once

namespace RFC {
    /**
     * @brief The status of a packet
     */
    enum Status {
        /** The packet is correct, operation successfully executed */
        OK = 200,
        /** The packet was not correctly formatted */
        UNKNOW = 400,
        /** The packet was correctly formatted but the operation failed */
        KO = 500,
    };
}; // namespace RFC
