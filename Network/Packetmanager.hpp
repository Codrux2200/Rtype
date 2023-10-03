/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packetmanager
*/

#pragma once

#include <vector>
#include "Packet.hpp"

namespace Network {
    class PacketManager {
        public:
            PacketManager() = default;
            ~PacketManager() = default;

            std::unique_ptr<Network::Packet> createPacket(
            Network::PacketType type, Status status, std::string message,
            void *data = nullptr);

            std::vector<char> packetToBytes(const Packet &packet);

            std::unique_ptr<Packet> bytesToPacket(
            const char *bytes, std::size_t bytes_size);

        private:
            int _id = 0;
            int _sequence = 0;
            short _replication = 0;
    };
} // namespace Network
