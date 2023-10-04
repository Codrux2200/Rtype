/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packetmanager
*/

#pragma once

#include <memory>
#include <vector>
#include "Packet.hpp"

#define PACKET_SIZE 32

namespace Network {
    class PacketManager {
        public:
            PacketManager() = default;
            ~PacketManager() = default;

            std::unique_ptr<Packet> createPacket(
            PacketType type, void *data = nullptr);

            std::vector<char> packetToBytes(const Packet &packet);

            std::unique_ptr<Packet> bytesToPacket(
            const char *bytes, std::size_t bytes_size);

        private:
    };
} // namespace Network
