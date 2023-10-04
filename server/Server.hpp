/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Server
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

// clang-format off
#include "Client.hpp"
#include "PacketManager.hpp"

// clang-format on
using boost::asio::ip::udp;

namespace RType {
    class Server {
        public:
            Server(boost::asio::io_service &io_service, short port);
            ~Server();

        private:
            std::shared_ptr<Client> _getClientByEndpoint(
            const udp::endpoint &endpoint);

            void _startReceive();

            void _handleReceive(const boost::system::error_code &error,
            std::size_t bytes_transferred);

            void _broadcastMessage(const std::string &message);

            void _handleSend(std::vector<char> message,
            boost::system::error_code error, std::size_t bytes_transferred);

            void _startClientCleanupTimer(boost::asio::io_service &io_service);

            void _sendMessageToClient(
            Network::Packet &packet, const udp::endpoint &client_endpoint);

            void _cleanupInactiveClients();

            void _sendConnectPacket(void);

            udp::socket _socket;
            udp::endpoint _remoteEndpoint;
            boost::array<char, PACKET_SIZE> _recvBuffer;
            std::vector<std::shared_ptr<Client>> _clients;
            Network::PacketManager _packetManager;
            std::shared_ptr<boost::asio::steady_timer> _clientCleanupTimer;

            static constexpr int CLIENT_TIMEOUT_SECONDS = 180;
            static constexpr int CLIENT_CLEANUP_INTERVAL_SECONDS = 60;
    };
} // namespace RType
