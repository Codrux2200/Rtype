/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Client
*/

#pragma once

#include <boost/asio.hpp>
#include <chrono>
#include <iostream>

#include "Client.hpp"

using boost::asio::ip::udp;

namespace RType {
    /**
     * @brief A Client is a class that represents a client connected to the
     * server, for the server.
     * It is used by the server to store information about the client, like its
     * name, its endpoint, and the time of its last activity.
     *
     */
    class Client {
        public:
            Client(const udp::endpoint &endpoint, const std::string &name)
                : _last_activity(std::chrono::steady_clock::now()),
                  _endpoint(endpoint), _name(name) {};
            ~Client()
            {
                std::cout << "Client " << _endpoint << " destroyed"
                          << std::endl;
            };

            const udp::endpoint &getEndpoint() const;

            const std::chrono::steady_clock::time_point &
            getLastActivity() const;

            void setLastActivity(std::chrono::steady_clock::time_point time);

            const std::string &getName() const;

            void setLeader(bool lead);

            bool isLeader(void) const;

            bool operator==(const Client &rhs) const;

        private:
            /**
             * @brief The time of the last activity of the client.
             * It is used to determine if the client is still connected or not.
             * If the client is not connected anymore, the server will
             * consider it as disconnected.
             */
            std::chrono::steady_clock::time_point _last_activity;

            /**
             * @brief The endpoint of the client.
             * It is used to send packets to the client, and to identify it.
             */
            udp::endpoint _endpoint;

            /**
             * @brief The name of the client.
             * It is the first thing the client sends to the server.
             */
            std::string _name;

            /**
             * @brief A boolean that indicates if the client is the leader or
             * not.
             * It is used to determine if the client can manage the game or not.
             * There can be only one leader at a time.
             */
            bool _isLeader = false;
    };

    using client_ptr = std::shared_ptr<Client>;

} // namespace RType
