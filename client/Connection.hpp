/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Connection
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "PacketManager.hpp"

using boost::asio::ip::udp;

class Connection {
    public:
        Connection(boost::asio::io_service &io_service, const std::string &host,
        const std::string &port);
        ~Connection();

        void sendPacket(const Network::Packet &packet);
        void quit(void);

    private:
        void _listen();

        udp::socket _socket;
        udp::resolver _resolver;
        udp::endpoint _endpoint;
        Network::PacketManager _packetManager;
        boost::array<char, PACKET_SIZE> _recv_buffer;
        udp::endpoint _sender_endpoint;
};
