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
    _loadPacketHandlers();
}

RType::Server::~Server()
{
}

void RType::Server::_loadPacketHandlers()
{
    packetManager.REGISTER_HANDLER(
    Network::PacketType::JOIN, &Server::_handlerJoin);
    packetManager.REGISTER_HANDLER(
    Network::PacketType::QUIT, &Server::_handlerQuit);
}

/**
 * @brief This admit that the client is connected to the server.
 *
 * @param packet
 */
void RType::Server::_handlerJoin(Network::Packet &/* packet */, const udp::endpoint &/* endpoint */)
{
    Network::data::ConnectData connectData{};

    // Set all player names to empty
    for (auto &player : connectData.players) {
        std::memset(player, '\0', NAME_LENGTH);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        std::memcpy(connectData.players[i], client->getName().c_str(),
        client->getName().size());
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = clientManager.getClientById(i);
        if (client == nullptr)
            continue;
        connectData.id = i;
        std::unique_ptr<Network::Packet> connectPacket =
        Network::PacketManager::createPacket(Network::PacketType::CONNECT, &connectData);
        _sendMessageToClient(*connectPacket, client->getEndpoint());
    }

    _broadcastNewLeader(
    clientManager.getClientId(clientManager.getLeader()->getEndpoint()));
}

void RType::Server::_handlerQuit(Network::Packet & packet, const udp::endpoint &endpoint){
    clientManager.unregisterClient(endpoint);
    if (clientManager.getLeader() == nullptr) {
        clientManager.setNewLeader();
        _broadcastNewLeader(
        clientManager.getClientId(clientManager.getLeader()->getEndpoint()));
    }
    char remoteClient = clientManager.getClientId(endpoint);
    auto _packet = Network::PacketManager::createPacket(
    Network::PacketType::DISCONNECT,
    &remoteClient);
    broadcast(*_packet);
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
        //std::cout << "Received message" << std::endl;

        //std::cout << "Sent by: " << _remoteEndpoint << std::endl;

        std::unique_ptr<Network::Packet> packet =
        Network::PacketManager::bytesToPacket(_recvBuffer.data(), bytesTransferred);

        RType::client_ptr client = _newClientPacket(packet);

        if (client != nullptr) {
            for (auto &cur : packetManager.recvPacketsQueue) {
                if (cur.first == client->getEndpoint() && cur.second.type == packet->type) {
                    _startReceive();
                    return;
                }
            }

            packetManager.addPacketToRecvQueue(*packet, client->getEndpoint());
            std::cout << "Packet added to queue" << std::endl;

            // Check if there is a leader
            if (clientManager.getLeader() == nullptr) {
                clientManager.setNewLeader();
            }
        }
    }
    _startReceive();
}

RType::client_ptr RType::Server::_newClientPacket(
std::unique_ptr<Network::Packet> &packet)
{
    RType::client_ptr client =
    clientManager.getClientByEndpoint(_remoteEndpoint);

    if (client != nullptr) {
        client->setLastActivity(std::chrono::steady_clock::now());
        return client;
    }

    if (packet->type != Network::PacketType::JOIN)
        return nullptr;

    for (int i = 0; i < NAME_LENGTH && (packet->joinData.name[i] || i == 0);
         i++) {
        if (packet->joinData.name[i] < 32 || packet->joinData.name[i] > 126) {
            std::cout << "Invalid name" << std::endl;
            return nullptr;
        }
    }

    std::string name = std::string(packet->joinData.name, NAME_LENGTH);

    if (!clientManager.registerClient(_remoteEndpoint, name)) {
        std::cout << "Too many clients connected, rejecting message"
                  << std::endl;
        return nullptr;
    } else {
        client = clientManager.getClientByEndpoint(_remoteEndpoint);
    }
    return client;
}

void RType::Server::sendCurrentLeader(const udp::endpoint &endpoint)
{
    auto leader = clientManager.getLeader();
    if (leader == nullptr)
        return;
    Network::data::LeaderData leaderData{};

    leaderData.leaderId = clientManager.getClientId(leader->getEndpoint());

    std::unique_ptr<Network::Packet> leaderPacket =
    Network::PacketManager::createPacket(Network::PacketType::LEADER, &leaderData);

    _sendMessageToClient(*leaderPacket, endpoint);
}

void RType::Server::broadcast(const Network::Packet &packet)
{
    std::cout << "Broadcasting packet" << std::endl;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto client = clientManager.getClientById(i);
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
            clientManager.unregisterClient(client->getEndpoint());
            if (isLeader) {
                clientManager.setNewLeader();
                _broadcastNewLeader(clientManager.getClientId(
                clientManager.getLeader()->getEndpoint()));
            }
        } else {
            std::cout << "Sending to: " << client->getName() << std::endl;
            _sendMessageToClient(
            const_cast<Network::Packet &>(packet), client->getEndpoint());
        }
    }
}

void RType::Server::_broadcastNewLeader(int id)
{
    Network::data::LeaderData leaderData{};

    leaderData.leaderId = id;

    std::unique_ptr<Network::Packet> leaderPacket =
    Network::PacketManager::createPacket(Network::PacketType::LEADER, &leaderData);

    broadcast(*leaderPacket);
}

void RType::Server::_handleSend(const std::vector<char>& message,
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
            if (this->clientManager.cleanupInactiveClients()) {
                if (this->clientManager.getLeader() == nullptr) {
                    this->clientManager.setNewLeader();
                    this->_broadcastNewLeader(this->clientManager.getClientId(
                    this->clientManager.getLeader()->getEndpoint()));
                }
            }
            _startClientCleanupTimer(ioService);
        }
    });
}

void RType::Server::_sendMessageToClient(
Network::Packet &packet, const udp::endpoint &clientEndpoint)
{
    std::vector<char> packetInBytes = Network::PacketManager::packetToBytes(packet);

    _socket.async_send_to(boost::asio::buffer(packetInBytes), clientEndpoint,
    boost::bind(&Server::_handleSend, this, packetInBytes,
    boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}

void RType::Server::sendPackets()
{
    if (!sendPacketsQueue.empty())
        std::cout << "Sending " << sendPacketsQueue.size() << " packets" << std::endl;
    for (auto &packet : sendPacketsQueue) {
        _sendMessageToClient(packet.second, packet.first->getEndpoint());
    }
    if (!sendPacketsQueue.empty())
        std::cout << "Sent " << sendPacketsQueue.size() << " packets" << std::endl;
    sendPacketsQueue.clear();
}
