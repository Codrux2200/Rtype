/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PacketManager
*/

#include "PacketManager.hpp"
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "Packet.hpp"

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
        default: throw std::runtime_error("Invalid packet type"); break;
    }
    return packet;
}
