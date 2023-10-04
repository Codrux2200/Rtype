/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Server
*/

#include "Server.hpp"
#include "Packet.hpp"

RType::Server::Server(boost::asio::io_service &io_service, short port)
    : _socket(io_service, udp::endpoint(udp::v4(), port))
{
    _startReceive();
    _startClientCleanupTimer(io_service);
}

RType::Server::~Server()
{
}

void RType::Server::_startReceive()
{
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer),
    _remoteEndpoint,
    boost::bind(&Server::_handleReceive, this, boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}

void RType::Server::_handleReceive(
const boost::system::error_code &error, std::size_t bytesTransferred)
{
    if (!error || error == boost::asio::error::message_size) {
        std::cout << "Received message" << std::endl;

        std::cout << "Sent by: " << _remoteEndpoint << std::endl;

        std::unique_ptr<Network::Packet> packet =
        _packetManager.bytesToPacket(_recvBuffer.data(), bytesTransferred);

        if (_clients.size() >= 4) {
            std::cout << "Too many clients connected, rejecting message"
                      << std::endl;

            // Send a rejection message to the client
            // TODO: Replace CONNECT Packet rejected
            // _send_message_to_client(
            // "Server is busy, try again later", _remote_endpoint);
        } else {
            bool clientAlreadyConnected = false;

            for (auto client : _clients) {
                if (client->getEndpoint() == _remoteEndpoint) {
                    // Client already connected, update last
                    // activity time
                    client->setLastActivity(std::chrono::steady_clock::now());
                    clientAlreadyConnected = true;
                    break;
                }
            }

            if (!clientAlreadyConnected) {
                // Store the remote endpoint (client) in a list
                std::cout << "New client connected: " << _remoteEndpoint
                          << std::endl;
                if (packet->type != Network::PacketType::JOIN)
                    return;
                std::string name = packet->joinData.name;
                _clients.push_back(
                std::make_shared<Client>(_remoteEndpoint, name));
                std::cout << "Client " << name << " connected" << std::endl;
                std::cout << "Number of clients connected: " << _clients.size()
                          << std::endl;
            }

            switch (packet->type) {
                case (Network::PacketType::JOIN): _sendConnectPacket(); break;
                default: break;
            }
        }
        _startReceive();
    }
}

void RType::Server::_sendConnectPacket(void)
{
    Network::data::ConnectData connectData;

    // Set all player names to empty
    for (int i = 0; i < 4; i++) {
        std::memset(connectData.players[i], '\0', NAME_LENGTH);
    }

    int i = 0;
    for (const auto& client : _clients) {
        std::memcpy(connectData.players[i++], client->getName().c_str(),
        client->getName().size());
    }

    std::unique_ptr<Network::Packet> connectPacket =
    _packetManager.createPacket(Network::PacketType::CONNECT, &connectData);
    _sendMessageToClient(*connectPacket, _remoteEndpoint);
}

void RType::Server::_broadcastDisconnect(char id)
{
    Network::data::DisconnectData disconnectData;

    disconnectData.id = id;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] == nullptr)
            continue;
        std::unique_ptr<Network::Packet> disconnectPacket =
        _packetManager.createPacket(Network::PacketType::DISCONNECT, &disconnectData);
        _sendMessageToClient(*disconnectPacket, _clients[i]->getEndpoint());
    }
};

void RType::Server::_broadcastMessage(const std::string &message)
{
    for (auto it = _clients.begin(); it != _clients.end();) {
        auto clientEndpoint = (*it)->getEndpoint();
        auto lastActivityTime = (*it)->getLastActivity();
        auto currentTime = std::chrono::steady_clock::now();
        auto timeSinceLastActivity =
        std::chrono::duration_cast<std::chrono::seconds>(
        currentTime - lastActivityTime)
        .count();

        if (timeSinceLastActivity > CLIENT_TIMEOUT_SECONDS) {
            // Client has not sent data for a while, consider it
            // disconnected
            std::cout << "Client disconnected: " << clientEndpoint << std::endl;
            it = _clients.erase(it); // Remove the disconnected client
        } else {
            // Send the message to the client
            // _send_message_to_client(message, client_endpoint);
            ++it;
        }
    }
}

void RType::Server::_handleSend(std::vector<char> message,
boost::system::error_code error, std::size_t bytesTransferred)
{
    if (!error) {
        std::cout << "Message sent" << std::endl;
    } else {
        std::cout << "Error sending message: " << error.message() << std::endl;
    }
}

void RType::Server::_startClientCleanupTimer(boost::asio::io_service &ioService)
{
    // This timer will periodically check for inactive clients and
    // remove them
    _clientCleanupTimer =
    std::make_shared<boost::asio::steady_timer>(ioService);

    _clientCleanupTimer->expires_from_now(
    std::chrono::seconds(CLIENT_CLEANUP_INTERVAL_SECONDS));

    _clientCleanupTimer->async_wait(
    [this, &ioService](const boost::system::error_code &ec) {
        if (!ec) {
            _cleanupInactiveClients();
            _startClientCleanupTimer(ioService);
        }
    });
}

void RType::Server::_sendMessageToClient(
Network::Packet &packet, const udp::endpoint &clientEndpoint)
{
    std::vector<char> packetInBytes = _packetManager.packetToBytes(packet);

    _socket.async_send_to(boost::asio::buffer(packetInBytes), clientEndpoint,
        boost::bind(&Server::_handleSend, this, packetInBytes,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void RType::Server::_cleanupInactiveClients()
{
    auto currentTime = std::chrono::steady_clock::now();

    std::cout << "Cleaning up inactive clients..." << std::endl;
    for (auto it = _clients.begin(); it != _clients.end();) {
        auto lastActivityTime = (*it)->getLastActivity();
        auto timeSinceLastActivity =
        std::chrono::duration_cast<std::chrono::seconds>(
        currentTime - lastActivityTime)
        .count();

        if (timeSinceLastActivity > CLIENT_TIMEOUT_SECONDS) {
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

std::shared_ptr<RType::Client> RType::Server::_getClientByEndpoint(
const udp::endpoint &endpoint)
{
    for (auto client : _clients) {
        if (client->getEndpoint() == endpoint) {
            return client;
        }
    }
    return nullptr;
}
