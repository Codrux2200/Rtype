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

using boost::asio::ip::udp;

namespace RType {
    class Client {
        public:
            Client(udp::endpoint endpoint, std::string &name)
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

        private:
            std::chrono::steady_clock::time_point _last_activity;
            udp::endpoint _endpoint;
            std::string _name;
            bool _isLeader = false;
    };
} // namespace RType
