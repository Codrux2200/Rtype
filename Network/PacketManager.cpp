/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PacketManager
*/

#include <cstring>
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <vector>

// clang-format off
#include "PacketManager.hpp"
#include "Packet.hpp"

// clang-format on
std::vector<char> Network::PacketManager::packetToBytes(
const Network::Packet &packet)
{
    std::vector<char> bytes;
    const char *packetType = reinterpret_cast<const char *>(&packet);

    for (unsigned long i = 0; i < sizeof(packet); i++)
        bytes.push_back(packetType[i]);
    return bytes;
}

std::unique_ptr<Network::Packet> Network::PacketManager::bytesToPacket(
const char *bytes, std::size_t bytes_size)
{
    std::unique_ptr<Network::Packet> packet =
    std::make_unique<Network::Packet>();

    memcpy(packet.get(), bytes, bytes_size);
    return packet;
}

std::unique_ptr<Network::Packet> Network::PacketManager::createPacket(
Network::PacketType type, void *data)
{
    if (data == nullptr)
        return nullptr;
    std::unique_ptr<Network::Packet> packet =
    std::make_unique<Network::Packet>();

    packet->type = type;
    switch (type) {
        case Network::PacketType::CONNECT:
            memcpy(&packet->connectData, data, sizeof(packet->connectData));
            break;
        case Network::PacketType::DISCONNECT:
            memcpy(
            &packet->disconnectData, data, sizeof(packet->disconnectData));
            break;
        case Network::PacketType::START:
            memcpy(&packet->startData, data, sizeof(packet->startData));
            break;
        case Network::PacketType::JOIN:
            memcpy(&packet->joinData, data, sizeof(packet->joinData));
            break;
        case Network::PacketType::LEADER:
            memcpy(&packet->leaderData, data, sizeof(packet->leaderData));
            break;
        default: throw std::runtime_error("Invalid packet type"); break;
    }
    return packet;
}

void Network::PacketManager::registerHandler(
Network::PacketType type, std::function<void(Network::Packet &)> handler)
{
    _handlers[type] = handler;
}

void Network::PacketManager::handlePacket(Network::Packet &packet)
{
    if (_handlers.find(packet.type) == _handlers.end()) {
        std::cerr << "No handler for packet type: "
                  << static_cast<int>(packet.type) << std::endl;
        return;
    }
    std::cout << "Handling packet type: " << static_cast<int>(packet.type)
              << std::endl;
    _handlers[packet.type](packet);
}
