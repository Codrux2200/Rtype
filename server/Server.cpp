/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Server
*/

#include "Server.hpp"
#include "LeaderData.hpp"

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

        RType::client_ptr client =
        _clientManager.getClientByEndpoint(_remoteEndpoint);

        if (client == nullptr) {
            if (packet->type != Network::PacketType::JOIN)
                return;
            std::string name = std::string(packet->joinData.name);
            if (_clientManager.registerClient(_remoteEndpoint, name) == false) {
                std::cout << "Too many clients connected, rejecting message"
                          << std::endl;
                return;
            } else {
                client = _clientManager.getClientByEndpoint(_remoteEndpoint);

                if (_clientManager.getLeader() == nullptr) {
                    client->setLeader(true);
                    std::cout << "New leader: " << client->getName()
                              << std::endl;
                }
            }
        }

        client->setLastActivity(std::chrono::steady_clock::now());

        switch (packet->type) {
            case (Network::PacketType::JOIN):
                _broadcastConnectPacket();
                _sendCurrentLeader(_remoteEndpoint);
                break;
            default: break;
        }

        if (_clientManager.getLeader() == nullptr) {
            _clientManager.setNewLeader();
        }
    }
    _startReceive();
}

void RType::Server::_sendCurrentLeader(const udp::endpoint &endpoint)
{
    auto leader = _clientManager.getLeader();
    if (leader == nullptr)
        return;
    Network::data::LeaderData leaderData;

    leaderData.leaderId = _clientManager.getClientId(leader->getEndpoint());

    std::unique_ptr<Network::Packet> leaderPacket =
    _packetManager.createPacket(Network::PacketType::LEADER, &leaderData);

    _sendMessageToClient(*leaderPacket, endpoint);
}

void RType::Server::_broadcastConnectPacket(void)
{
    Network::data::ConnectData connectData;

    // Set all player names to empty
    for (int i = 0; i < MAX_PLAYERS; i++) {
        std::memset(connectData.players[i], '\0', NAME_LENGTH);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = _clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        std::memcpy(connectData.players[i], client->getName().c_str(),
        client->getName().size());
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = _clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        connectData.id = i;
        std::unique_ptr<Network::Packet> connectPacket =
        _packetManager.createPacket(Network::PacketType::CONNECT, &connectData);
        _sendMessageToClient(*connectPacket, client->getEndpoint());
    }
}

void RType::Server::_broadcast(const Network::Packet &packet)
{
    std::cout << "Broadcasting packet" << std::endl;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = _clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        auto lastActivityTime = client->getLastActivity();
        auto currentTime = std::chrono::steady_clock::now();
        auto timeSinceLastActivity =
        std::chrono::duration_cast<std::chrono::seconds>(
        currentTime - lastActivityTime)
        .count();

        if (timeSinceLastActivity > CLIENT_TIMEOUT_SECONDS) {
            // Client has not sent data for a while, consider it
            // disconnected
            std::cout << "Client disconnected: " << client->getName()
                      << std::endl;
            bool isLeader = client->isLeader();
            _clientManager.unregisterClient(client->getEndpoint());
            if (isLeader) {
                _clientManager.setNewLeader();
                _broadcastNewLeader(_clientManager.getClientId(
                _clientManager.getLeader()->getEndpoint()));
            }
        } else {
            std::cout << "Sending to: " << client->getName() << std::endl;
            _sendMessageToClient(
            const_cast<Network::Packet &>(packet), client->getEndpoint());
        }
    }
}

// void RType::Server::_setNewLeader(void)
// {
//     for (int i = 0; i < MAX_PLAYERS; i++) {
//         if (_clients[i] == nullptr)
//             continue;
//         _clients[i]->setLeader(true);
//         std::cout << "New leader: " << _clients[i]->getName() << std::endl;
//         _broadcastNewLeader(i);
//         break;
//     }
// }

void RType::Server::_broadcastNewLeader(int id)
{
    Network::data::LeaderData leaderData;

    leaderData.leaderId = id;

    std::unique_ptr<Network::Packet> leaderPacket =
    _packetManager.createPacket(Network::PacketType::LEADER, &leaderData);

    _broadcast(*leaderPacket);
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
            if (this->_clientManager.cleanupInactiveClients()) {
                if (this->_clientManager.getLeader() == nullptr) {
                    this->_clientManager.setNewLeader();
                    this->_broadcastNewLeader(this->_clientManager.getClientId(
                    this->_clientManager.getLeader()->getEndpoint()));
                }
            }
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

// void RType::Server::_cleanupInactiveClients()
// {
//     auto currentTime = std::chrono::steady_clock::now();

//     std::cout << "Cleaning up inactive clients..." << std::endl;
//     for (int i = 0; i < MAX_PLAYERS; i++) {
//         auto client = _clients[i];
//         if (client == nullptr)
//             continue;
//         auto lastActivityTime = client->getLastActivity();
//         auto timeSinceLastActivity =
//         std::chrono::duration_cast<std::chrono::seconds>(
//         currentTime - lastActivityTime)
//         .count();

//         if (timeSinceLastActivity > CLIENT_TIMEOUT_SECONDS) {
//             // Client has not sent data for a while, consider it
//             // disconnected
//             std::cout << "Client disconnected: " << client->getName()
//                       << std::endl;
//             bool isLeader = client->isLeader();
//             _clients[i] = nullptr; // Remove the disconnected client
//             if (isLeader)
//                 _setNewLeader();
//         } else {
//         }
//     }
// }
