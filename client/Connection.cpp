/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Connection
*/

#include <iostream>
#include "Connection.hpp"

RType::Connection::Connection(boost::asio::io_service &io_service,
const std::string &host, const std::string &port, const std::string &name)
    : _socket(io_service), _resolver(io_service)
{
    _endpoint = *_resolver.resolve(udp::v4(), host, port).begin();
    _socket.open(udp::v4());
    _name = name;

    _initHandlers();

    _listen();
    _stayConnected(io_service);
}

void RType::Connection::_stayConnected(boost::asio::io_service &io_service)
{
    _stayConnectedTimer = std::make_shared<boost::asio::steady_timer>(io_service);

    _stayConnectedTimer->expires_from_now(std::chrono::seconds(2));

    _stayConnectedTimer->async_wait([this, &io_service](const boost::system::error_code &error) {
        if (!error) {
            if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - _lastPacketSent).count() > 3) {
                std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::I_AM_HERE, nullptr);
                sendPacket(*packet);
            }
            _stayConnected(io_service);
        }
    });
}

RType::Connection::~Connection()
{
}

void RType::Connection::_initHandlers()
{
    packetManager.REGISTER_HANDLER(
    Network::PacketType::LEADER, &RType::Connection::_handlerLeader);
}

void RType::Connection::_listen()
{
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer),
    _endpoint,
    [&](const boost::system::error_code &error, std::size_t bytes_received) {
        std::cout << "Received " << bytes_received << " bytes" << std::endl; 
        if (!error && bytes_received == 36) {
            packetManager.mutex.lock();

            std::unique_ptr<Network::Packet> packet = Network::PacketManager::bytesToPacket(
                _recvBuffer.data(), bytes_received);
            packetManager.recvPacketsQueue.emplace_back(
                _endpoint, *packet);

            packetManager.mutex.unlock();
        } else {
            std::cerr << "Error receiving response: " << error.message() << std::endl;
        }
        _listen();
    });
}

void RType::Connection::_handlerLeader(Network::Packet &packet, const udp::endpoint &endpoint)
{
    std::cout << "Leader: " << (int) packet.leaderData.leaderId << std::endl;
}

void RType::Connection::sendPacket(const Network::Packet &packet)
{
    std::vector<char> packetInBytes = Network::PacketManager::packetToBytes(packet);

    // stores the time as now to know when the last packet was sent
    _lastPacketSent = std::chrono::system_clock::now();

    _socket.async_send_to(boost::asio::buffer(packetInBytes), _endpoint,
    [](const boost::system::error_code &error, std::size_t bytes_sent) {
        if (error) {
            std::cerr << "Error sending message: " << error.message()
                      << std::endl;
        }
    });
}

void RType::Connection::sendPackets()
{
    for (auto &packet : packetManager.sendPacketsQueue) {
        sendPacket(packet);
    }
    packetManager.sendPacketsQueue.clear();
}

void RType::Connection::handlePackets()
{
    std::lock_guard<std::mutex> lock(packetManager.mutex);

    for (auto &packet : packetManager.recvPacketsQueue) {
        packetManager.handlePacket(packet.second, packet.first);
    }
    packetManager.recvPacketsQueue.clear();
}

void RType::Connection::tryConnect()
{

    std::cout << "Trying to connect to " << _endpoint.address().to_string() << ":" << _endpoint.port() << std::endl;
    struct Network::data::JoinData joinData{};

    std::memset(&joinData.name, 0, sizeof(char) * NAME_LENGTH);

    for (int i = 0; i < NAME_LENGTH && i < (int) _name.size(); i++)
        joinData.name[i] = _name[i];

    std::unique_ptr<Network::Packet> packet =
    Network::PacketManager::createPacket(Network::PacketType::JOIN, &joinData);

    sendPacket(*packet);

}
