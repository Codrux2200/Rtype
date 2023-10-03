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
    _listen();
    struct Network::data::HubData hubData;

    for (int i = 0; i < 4; i++) {
        std::strcpy(hubData.players[i], "Player");
        std::strcat(hubData.players[i], std::to_string(i).c_str());
    }

    std::unique_ptr<Network::Packet> packet = _packetManager.createPacket(
    Network::PacketType::CONNECT, Network::Status::OK, "", &hubData);
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
            std::cout << "Packet id: " << packet->id << std::endl;
            std::cout << "Packet sequence: " << packet->sequence << std::endl;
            std::cout << "Packet replication: " << packet->replication
                      << std::endl;
            std::cout << "Packet status" << packet->status << std::endl;
            std::cout << "Packet timestamp: " << packet->timestamp << std::endl;
            std::cout << "Packet message: " << packet->message << std::endl;
            std::cout << "Packet data: " << std::endl;
            switch (packet->type) {
                case Network::CONNECT:
                    for (int i = 0; i < 4; i++) {
                        std::cout << "Player " << i << ": "
                                  << packet->connectData.players[i]
                                  << std::endl;
                    }
                    break;
                default: break;
            }
            std::cout << std::endl;
        } else {
            std::cerr << "Error receiving response: " << error.message()
                      << std::endl;
        }
    });
}

void Connection::sendPacket(const Network::Packet &packet)
{
    std::vector<char> packetInBytes = _packetManager.packetToBytes(packet);

    _socket.async_send_to(boost::asio::buffer(packetInBytes), _endpoint,
    [](const boost::system::error_code &error, std::size_t bytes_sent) {
        if (!error) {
            std::cout << "Sent message to server." << std::endl;
        } else {
            std::cerr << "Error sending message: " << error.message()
                      << std::endl;
        }
    });
}
