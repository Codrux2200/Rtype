/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Connection
*/

#include "Connection.hpp"
#include <iostream>

Connection::Connection(boost::asio::io_service &io_service,
const std::string &host, const std::string &port)
    : _socket(io_service), _resolver(io_service)
{
    _endpoint = *_resolver.resolve(udp::v4(), host, port).begin();
    _socket.open(udp::v4());
    std::cout << "Connected to " << host << ":" << port << std::endl;
    struct Network::data::JoinData joinData;

    if (std::rand() % 2 == 0)
        std::memcpy(joinData.name, "Guigu", 5);
    else
        std::memcpy(joinData.name, "Sebou", 5);

    joinData.name[5] = '\0';

    std::unique_ptr<Network::Packet> packet =
    _packetManager.createPacket(Network::PacketType::JOIN, &joinData);

    _listen();
    sendPacket(*packet);
}

Connection::~Connection()
{
}

void Connection::_listen()
{
    _socket.async_receive_from(boost::asio::buffer(_recv_buffer),
    _sender_endpoint,
    [&](const boost::system::error_code &error, std::size_t bytes_received) {
        if (!error) {
            std::unique_ptr<Network::Packet> packet =
            _packetManager.bytesToPacket(_recv_buffer.data(), bytes_received);
            std::cout << "Received packet from server: " << std::endl;
            std::cout << "Packet type: " << packet->type << std::endl;
            switch (packet->type) {
                case Network::CONNECT:
                    std::cout << "Your id: " << (int) packet->connectData.id
                              << std::endl;
                    for (int i = 0; i < 4; i++) {
                        std::cout << "Player " << i << ": "
                                  << packet->connectData.players[i]
                                  << std::endl;
                    }
                    break;
                case Network::LEADER:
                    std::cout << "Leader: " << (int) packet->leaderData.leaderId
                              << std::endl;
                    break;
                default:
                    throw std::runtime_error("Invalid packet type received");
                    break;
            }
            std::cout << std::endl;
        } else {
            std::cerr << "Error receiving response: " << error.message()
                      << std::endl;
        }
        _listen();
    });
}

void Connection::sendPacket(const Network::Packet &packet)
{
    std::vector<char> packetInBytes = _packetManager.packetToBytes(packet);

    _socket.async_send_to(boost::asio::buffer(packetInBytes), _endpoint,
    [](const boost::system::error_code &error, std::size_t bytes_sent) {
        if (!error) {
            std::cout << "Sent packet to server." << std::endl;
        } else {
            std::cerr << "Error sending message: " << error.message()
                      << std::endl;
        }
    });
}
