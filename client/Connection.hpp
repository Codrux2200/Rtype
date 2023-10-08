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

namespace RType {

    /**
     * @brief A Connection is a class that represents a connection to a server.
     * It is used to send and receive packets from the server.
     *
     */
    class Connection {
        public:
            /**
             * @brief Construct a new Connection object
             *
             * @param io_service The boost::asio::io_service to use (or
             * io_context)
             * @param host The host to connect to (IP address)
             * @param port The port to connect to (IP port)
             */
            Connection(boost::asio::io_service &io_service,
            const std::string &host, const std::string &port,
            const std::string &name);
            ~Connection();

            /**
             * @brief Used to send a packet to the server
             *
             * @param packet The packet to send
             *
             * @see Network::Packet
             */
            void sendPacket(const Network::Packet &packet);

        private:
            /**
             * @brief Listen for incoming packets from the server
             *
             */
            void _listen();

            /**
             * @brief Initialize the handlers for the packets.
             */
            void _initHandlers();

            /* HANDLERS */
            void _handlerConnect(Network::Packet &packet);
            void _handlerLeader(Network::Packet &packet);
            void _handlerStart(Network::Packet &packet);

            udp::socket _socket;
            udp::resolver _resolver;
            udp::endpoint _endpoint;
            Network::PacketManager _packetManager;
            boost::array<char, PACKET_SIZE> _recv_buffer;
            udp::endpoint _sender_endpoint;
    };
} // namespace RType
