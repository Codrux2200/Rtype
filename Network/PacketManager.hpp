/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Packetmanager
*/

#pragma once

#include <map>
#include <memory>
#include <vector>
#include "Packet.hpp"

#define PACKET_SIZE 32

#define REGISTER_HANDLER(type, handler) \
    registerHandler(type, std::bind(handler, this, std::placeholders::_1));

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

            void registerHandler(
            PacketType type, std::function<void(Packet &)> handler);

            void handlePacket(Packet &packet);

        private:
            std::map<PacketType, std::function<void(Packet &)>> _handlers;
    };
} // namespace Network
