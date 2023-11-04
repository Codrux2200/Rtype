/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Clientmanager
*/

#include "ClientManager.hpp"
#include "DisconnectData.hpp"
#include "PacketManager.hpp"
#include "Server.hpp"

RType::ClientManager::ClientManager()
{
    _clients.fill(nullptr);
}

int RType::ClientManager::getClientId(const udp::endpoint &endpoint)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] && _clients[i]->getEndpoint() == endpoint)
            return i;
    }
    return -1;
}

std::shared_ptr<RType::Client> RType::ClientManager::getLeader(void)
{
    for (auto client : _clients) {
        if (client == nullptr)
            continue;
        if (client->isLeader()) {
            return client;
        }
    }
    return nullptr;
}

std::shared_ptr<RType::Client> RType::ClientManager::getClientByEndpoint(
const udp::endpoint &endpoint)
{
    for (auto client : _clients) {
        if (client == nullptr)
            continue;
        if (client->getEndpoint() == endpoint) {
            return client;
        }
    }
    return nullptr;
}

bool RType::ClientManager::registerClient(
const udp::endpoint &endpoint, const std::string &name)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] == nullptr) {
            _clients[i] = std::make_shared<Client>(endpoint, name);
            std::cout << "Client " << name << " connected" << std::endl;
            return true;
        }
    }
    return false;
}

void RType::ClientManager::unregisterClient(const udp::endpoint &endpoint)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] == nullptr)
            continue;
        if (_clients[i]->getEndpoint() == endpoint) {
            _clients[i] = nullptr;
            return;
        }
    }
}

bool RType::ClientManager::cleanupInactiveClients(RType::Server &server)
{
    bool isLeaderLoggedOut = false;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] == nullptr)
            continue;
        auto now = std::chrono::steady_clock::now();
        auto lastActivity = _clients[i]->getLastActivity();
        auto diff =
        std::chrono::duration_cast<std::chrono::seconds>(now - lastActivity);
        if (diff.count() > 5) {
            std::cout << "Client " << _clients[i]->getName() << " disconnected"
                      << std::endl;
            Network::data::DisconnectData disconnectData{};
            disconnectData.id = i;
            std::unique_ptr<Network::Packet> disconnectPacket =
            Network::PacketManager::createPacket(Network::PacketType::DISCONNECT,
            &disconnectData);
            server.broadcast(*disconnectPacket);
            if (_clients[i]->isLeader())
                isLeaderLoggedOut = true;
            _clients[i] = nullptr;
        }
    }
    return isLeaderLoggedOut;
}

bool RType::ClientManager::setNewLeader(void)
{
    if (getLeader() != nullptr)
        return true;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] == nullptr)
            continue;
        _clients[i]->setLeader(true);
        std::cout << "New leader: " << _clients[i]->getName() << std::endl;
        return true;
    }
    return false;
}

std::array<std::shared_ptr<RType::Client>, MAX_PLAYERS> &
RType::ClientManager::getClients(void)
{
    return _clients;
}

std::shared_ptr<RType::Client> RType::ClientManager::getClientById(int id)
{
    if (id < 0 || id >= MAX_PLAYERS)
        return nullptr;
    return _clients[id];
}
