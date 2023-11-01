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
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

// clang-format off
#include "Client.hpp"
#include "PacketManager.hpp"
#include "ConnectData.hpp"
#include "ClientManager.hpp"

// clang-format on
using boost::asio::ip::udp;

namespace RType {
    class Server {
        public:
            /**
             * @brief Construct a new Server object
             * @param io_service
             * @param port
             */
            Server(boost::asio::io_service &io_service, short port);
            /**
             * @brief Destroy the Server object
             */
            ~Server();

            /**
             * @brief Send the leader ID to the client of the given endpoint
             * @param endpoint
             */
            void sendCurrentLeader(const udp::endpoint &endpoint);

            /**
             * @brief The server's packet manager
             */
            Network::PacketManager packetManager;

            /**
             * @brief Sends all the packets in the sendPacketsQueue to all concerned clients
             */
            void sendPackets();

            /**
             * @brief Sends a given packet to a client of the given endpoint
             * @param packet
             * @param client_endpoint
             */
            void _sendMessageToClient(
            Network::Packet &packet, const udp::endpoint &client_endpoint);

            /**
             * @brief Broadcasts a given packet to all clients
             * @param packet
             */
            void broadcast(const Network::Packet &packet);

            /**
             * @brief Broadcasts the new leader ID to all clients
             */
            void broadcastNewLeader();

            /**
             * @brief The server's client manager
             */
            ClientManager clientManager;
            /**
             * @brief The server's reception packet queue
             */
            std::vector<std::pair<std::shared_ptr<Client>, std::unique_ptr<Network::Packet>>> recvPacketsQueue;
            /**
             * @brief The server's send packet queue
             */
            std::vector<std::pair<std::shared_ptr<Client>, Network::Packet>> sendPacketsQueue;
        private:
            /**
             * @brief Load the JOIN and QUIT packet handlers
             */
            void _loadPacketHandlers();

            /**
             * @brief Start the server's reception
             */
            void _startReceive();

            /**
             * @brief Handle the reception of a packet,
             * splits the received packets into different handlers functions
             * @param error
             * @param bytes_transferred
             */
            void _handleReceive(const boost::system::error_code &error,
            std::size_t bytes_transferred);

            /**
             * @brief Logs the emission of a packet, with the given error message and given bytes transferred
             * @param message
             * @param error
             * @param bytes_transferred
             */
            void _handleSend(const std::vector<char>& message,
            boost::system::error_code error, std::size_t bytes_transferred);

            /**
             * @brief Starts the client cleanup loop, which will remove inactive clients automatically
             * @param io_service
             */
            void _startClientCleanupTimer(boost::asio::io_service &io_service);

            /**
             * @brief Creates a new client packet and adds it to the client manager
             * @param packet
             * @return client_ptr
             */
            client_ptr _newClientPacket(
            std::unique_ptr<Network::Packet> &packet);

           /**
             * @brief Handles the QUIT packet
             * @param packet
             * @param endpoint
             */
            void _handlerQuit(Network::Packet &packet, const udp::endpoint &endpoint);

            /**
             * @brief Global first socket
             */
            udp::socket _socket;
            /**
             * @brief The current remote endpoint
             */
            udp::endpoint _remoteEndpoint;
            /**
             * @brief The receive buffer
             */
            boost::array<char, PACKET_SIZE> _recvBuffer{};
            /**
             * @brief The cleanup timerclock, defining the interval between each cleanup
             */
            std::shared_ptr<boost::asio::steady_timer> _clientCleanupTimer;
            /**
             * @brief The packet handlers map
             */
            std::map<Network::PacketType, std::function<void()>>
            _packetHandlers;

            /**
             * @brief Global server timeout variable, defining the time before a client is considered inactive
             */
            static constexpr int CLIENT_TIMEOUT_SECONDS = 180000;
            /**
             * @brief Global server cleanup interval variable, defining the interval between each cleanup, used by the cleanup timer
             */
            static constexpr int CLIENT_CLEANUP_INTERVAL_SECONDS = 10000;
    };
} // namespace RType
