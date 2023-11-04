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
#include "Packet.hpp"

namespace RType {

    /**
     * @brief A ClientManager is a class that manages the clients connected to
     * the server.
     * It is used to store the clients, and to get information about them.
     * It is also used to register and unregister clients.
     */
    class ClientManager {
        public:
            /**
             * @brief Construct a new ClientManager object
             */
            ClientManager();

            /**
             * @brief Get the id of a client from its endpoint
             *
             * @param endpoint
             * @return
             */
            int getClientId(const udp::endpoint &endpoint);

            /**
             * @brief Get the leader of the game
             *
             * @return std::shared_ptr<Client> The leader of the game
             */
            std::shared_ptr<Client> getLeader(void);

            /**
             * @brief Gets a client from its endpoint
             *
             * @param endpoint The endpoint of the client
             *
             * @return shared_ptr<Client> The client with the given endpoint
             */
            std::shared_ptr<Client> getClientByEndpoint(
            const udp::endpoint &endpoint);

            /**
             * @brief Register a client to the server
             *
             * @param endpoint Endpoint of the client
             * @param name Name of the client
             * @return bool True if the client was registered, false otherwise
             */
            bool registerClient(
            const udp::endpoint &endpoint, const std::string &name);

            /**
             * @brief Unregister a client from the server
             *
             * @param endpoint Endpoint of the client
             */
            void unregisterClient(const udp::endpoint &endpoint);

            /**
             * @brief Unregister and disconnects all inactive clients.
             * Will replace the leader if the leader is inactive.
             */
            bool cleanupInactiveClients(std::vector<Network::Packet> &packets);

            /**
             * @brief Set a new leader
             *
             * @return true If a new leader was set
             * @return false If no new leader was set
             */
            bool setNewLeader(void);

            /**
             * @brief Get all the clients
             *
             * @return std::array<std::shared_ptr<Client>, MAX_PLAYERS>& The
             * clients in an array
             */
            std::array<std::shared_ptr<Client>, MAX_PLAYERS> &getClients(void);

            /**
             * @brief Get a client by its id
             *
             * @param id The id of the client
             * @return std::shared_ptr<Client> The client with the given id
             */
            std::shared_ptr<Client> getClientById(int id);

        private:
            /**
             * @brief The array of clients
             */
            std::array<std::shared_ptr<Client>, MAX_PLAYERS> _clients;
    };
} // namespace RType
