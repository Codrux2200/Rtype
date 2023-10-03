/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Server
*/

#include "Server.hpp"

RType::Server::Server(boost::asio::io_service &io_service, short port)
    : _socket(io_service, udp::endpoint(udp::v4(), port))
{
    _start_receive();
    _start_client_cleanup_timer(io_service);
}

RType::Server::~Server()
{
}

void RType::Server::_start_receive()
{
    _socket.async_receive_from(boost::asio::buffer(_recv_buffer),
    _remote_endpoint,
    boost::bind(&Server::_handle_receive, this,
    boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}

void RType::Server::_handle_receive(
const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size) {
        std::cout << "Received message" << std::endl;

        std::cout << "Sent by: " << _remote_endpoint << std::endl;

        std::unique_ptr<Network::Packet> packet =
        _packet_manager.bytesToPacket(_recv_buffer.data(), bytes_transferred);

        if (_clients.size() >= 4) {
            std::cout << "Too many clients connected, rejecting message"
                      << std::endl;

            // Send a rejection message to the client
            // TODO: Replace CONNECT Packet rejected
            // _send_message_to_client(
            // "Server is busy, try again later", _remote_endpoint);
        } else {
            bool client_already_connected = false;

            for (auto client : _clients) {
                if (client->getEndpoint() == _remote_endpoint) {
                    // Client already connected, update last
                    // activity time
                    client->setLastActivity(std::chrono::steady_clock::now());
                    client_already_connected = true;
                    break;
                }
            }

            if (!client_already_connected) {
                // Store the remote endpoint (client) in a list
                std::cout << "New client connected: " << _remote_endpoint
                          << std::endl;
                _clients.push_back(std::make_shared<Client>(_remote_endpoint));
            }

            switch (packet->type) {
                case Network::PacketType::CONNECT:
                    Network::data::HubData hubData;

                    for (int i = 0; i < 4; i++) {
                        std::strcpy(hubData.players[i], "Player");
                        std::strcat(
                        hubData.players[i], std::to_string(i).c_str());
                    }
                    std::unique_ptr<Network::Packet> connectPacket =
                    _packet_manager.createPacket(Network::PacketType::CONNECT,
                    Network::Status::OK, "", &hubData);
                    _send_message_to_client(*packet, _remote_endpoint);
                    break;
            }
        }
        _start_receive();
    }
}

void RType::Server::_broadcast_message(const std::string &message)
{
    for (auto it = _clients.begin(); it != _clients.end();) {
        auto client_endpoint = (*it)->getEndpoint();
        auto last_activity_time = (*it)->getLastActivity();
        auto current_time = std::chrono::steady_clock::now();
        auto time_since_last_activity =
        std::chrono::duration_cast<std::chrono::seconds>(
        current_time - last_activity_time)
        .count();

        if (time_since_last_activity > CLIENT_TIMEOUT_SECONDS) {
            // Client has not sent data for a while, consider it
            // disconnected
            std::cout << "Client disconnected: " << client_endpoint
                      << std::endl;
            it = _clients.erase(it); // Remove the disconnected client
        } else {
            // Send the message to the client
            _socket.async_send_to(boost::asio::buffer(message), client_endpoint,
            boost::bind(&Server::_handle_send, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
            ++it;
        }
    }
}

void RType::Server::_handle_send(const std::string &message,
const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (!error) {
        std::cout << "Message : " << message << " sent" << std::endl;
    } else {
        std::cout << "Error sending message: " << error.message() << std::endl;
    }
}

void RType::Server::_start_client_cleanup_timer(
boost::asio::io_service &io_service)
{
    // This timer will periodically check for inactive clients and
    // remove them
    _client_cleanup_timer =
    std::make_shared<boost::asio::steady_timer>(io_service);

    _client_cleanup_timer->expires_from_now(
    std::chrono::seconds(CLIENT_CLEANUP_INTERVAL_SECONDS));

    _client_cleanup_timer->async_wait(
    [this, &io_service](const boost::system::error_code &ec) {
        if (!ec) {
            _cleanup_inactive_clients();
            _start_client_cleanup_timer(io_service);
        }
    });
}

void RType::Server::_send_message_to_client(
Network::Packet &packet, const udp::endpoint &client_endpoint)
{
    std::vector<char> packetInBytes = _packet_manager.packetToBytes(packet);

    _socket.async_send_to(boost::asio::buffer(packetInBytes), client_endpoint,
    boost::bind(&Server::_handle_send, this, packetInBytes,
    boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}

void RType::Server::_cleanup_inactive_clients()
{
    auto current_time = std::chrono::steady_clock::now();

    std::cout << "Cleaning up inactive clients..." << std::endl;
    for (auto it = _clients.begin(); it != _clients.end();) {
        auto last_activity_time = (*it)->getLastActivity();
        auto time_since_last_activity =
        std::chrono::duration_cast<std::chrono::seconds>(
        current_time - last_activity_time)
        .count();

        if (time_since_last_activity > CLIENT_TIMEOUT_SECONDS) {
            // Client has not sent data for a while, consider it
            // disconnected
            std::cout << "Client disconnected: " << (*it)->getEndpoint()
                      << std::endl;
            it = _clients.erase(it); // Remove the disconnected client
        } else {
            ++it;
        }
    }
}
