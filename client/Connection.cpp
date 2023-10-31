/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Connection
*/

#include "Connection.hpp"
#include <iostream>

RType::Connection::Connection(boost::asio::io_service &io_service,
const std::string &host, const std::string &port, const std::string &name)
    : _socket(io_service), _resolver(io_service)
{
    _endpoint = *_resolver.resolve(udp::v4(), host, port).begin();
    _socket.open(udp::v4());
    std::cout << "Connected to " << host << ":" << port << std::endl;
    struct Network::data::JoinData joinData;

    std::memset(&joinData.name, 0, sizeof(char) * NAME_LENGTH);

    for (int i = 0; i < NAME_LENGTH && i < (int) name.size(); i++)
        joinData.name[i] = name[i];

    std::unique_ptr<Network::Packet> packet =
    Network::PacketManager::createPacket(Network::PacketType::JOIN, &joinData);

    _initHandlers();

    _listen();
    sendPacket(*packet);
}

RType::Connection::~Connection()
{
}

void RType::Connection::_initHandlers()
{
    packetManager.REGISTER_HANDLER(
    Network::PacketType::LEADER, &RType::Connection::_handlerLeader);
}

void RType::Connection::_listen()
{
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer),
    _senderEndpoint,
    [&](const boost::system::error_code &error, std::size_t bytes_received) {
        if (!error) {
            packetManager.mutex.lock();

            std::unique_ptr<Network::Packet> packet = Network::PacketManager::bytesToPacket(
                _recvBuffer.data(), bytes_received);
            packetManager.recvPacketsQueue.emplace_back(
                _senderEndpoint, *packet);

            packetManager.mutex.unlock();
        } else {
            std::cerr << "Error receiving response: " << error.message() << std::endl;
        }
        _listen();
    });
}

void RType::Connection::_handlerLeader(Network::Packet &packet, const udp::endpoint &endpoint)
{
    std::cout << "Leader: " << (int) packet.leaderData.leaderId << std::endl;
}

void RType::Connection::sendPacket(const Network::Packet &packet)
{
    std::vector<char> packetInBytes = Network::PacketManager::packetToBytes(packet);

    _socket.async_send_to(boost::asio::buffer(packetInBytes), _endpoint,
    [](const boost::system::error_code &error, std::size_t bytes_sent) {
        if (error) {
            std::cerr << "Error sending message: " << error.message()
                      << std::endl;
        }
    });
}

void RType::Connection::sendPackets()
{
    for (auto &packet : packetManager.sendPacketsQueue) {
        sendPacket(packet);
    }
    packetManager.sendPacketsQueue.clear();
}

void RType::Connection::handlePackets()
{
    std::lock_guard<std::mutex> lock(packetManager.mutex);

    for (auto &packet : packetManager.recvPacketsQueue) {
        packetManager.handlePacket(packet.second, packet.first);
    }
    packetManager.recvPacketsQueue.clear();
}