/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ClientManager
*/

#pragma once

#include <array>
#include <memory>
#include "Client.hpp"
#include "ConnectData.hpp"

namespace RType {
    class ClientManager {
        public:
            ClientManager();

            int getClientId(const udp::endpoint &endpoint);

            std::shared_ptr<Client> getLeader(void);

            std::shared_ptr<Client> getClientByEndpoint(
            const udp::endpoint &endpoint);

            bool registerClient(
            const udp::endpoint &endpoint, const std::string &name);

            void unregisterClient(const udp::endpoint &endpoint);

            bool cleanupInactiveClients(void);

            bool setNewLeader(void);

            std::array<std::shared_ptr<Client>, MAX_PLAYERS> &getClients(void);

            std::shared_ptr<Client> getClientById(int id);

        private:
            std::array<std::shared_ptr<Client>, MAX_PLAYERS> _clients;
    };
} // namespace RType
