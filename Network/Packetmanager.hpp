/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packetmanager
*/

#pragma once

#include "Packet.hpp"

namespace Network {
    class PacketManager {
        public:
            PacketManager() = default;
            ~PacketManager() = default;

            Packet *createPacket(PacketType type, struct HubData &data);
            Packet *createPacket(PacketType type, struct StartData &data);
            Packet *createPacket(PacketType type, struct DisconnectData &data);

        private:
            int _id = 0;
            int _sequence = 0;
            short _replication = 0;
    };
} // namespace Network
