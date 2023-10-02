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

// clang-format on
using boost::asio::ip::udp;

namespace RType {
    class Server {
        public:
            Server(boost::asio::io_service &io_service, short port);
            ~Server();

        private:
            std::shared_ptr<Client> _get_client_by_endpoint(
            const udp::endpoint &endpoint);

            void _start_receive();

            void _handle_receive(const boost::system::error_code &error,
            std::size_t bytes_transferred);

            void _broadcast_message(const std::string &message);

            void _handle_send(const std::string &message,
            const boost::system::error_code &error,
            std::size_t bytes_transferred);

            void _start_client_cleanup_timer(
            boost::asio::io_service &io_service);

            void _send_message_to_client(
            const std::string &message, const udp::endpoint &client_endpoint);

            void _cleanup_inactive_clients();

            udp::socket _socket;
            udp::endpoint _remote_endpoint;
            boost::array<char, 512> _recv_buffer;
            std::vector<std::shared_ptr<Client>> _clients;
            std::shared_ptr<boost::asio::steady_timer> _client_cleanup_timer;

            static constexpr int CLIENT_TIMEOUT_SECONDS = 10;
            static constexpr int CLIENT_CLEANUP_INTERVAL_SECONDS = 5;
    };
} // namespace RType
