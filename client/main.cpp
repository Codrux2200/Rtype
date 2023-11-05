/*
** EPITECH PROJECT, 2023
** RType
** File description:
** main
*/

#include <boost/asio.hpp>
#include <thread>
#include "Connection.hpp"
#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cerr << "Usage: ./client <host> <port> <name>" << std::endl;
        return 84;
    }

    if (std::strtoll(av[2], nullptr, 10) < 0 ||
        std::strtoll(av[2], nullptr, 10) > 65535) {
        std::cerr << "Port must be between 0 and 65535" << std::endl;
        return 84;
    }

    if (std::strlen(av[3]) > 7) {
        std::cerr << "Name must be less than 7 characters" << std::endl;
        return 84;
    }

    boost::asio::io_service io_service;
    RType::Connection connection(io_service, av[1], av[2], av[3]);
    ECS::Core core(av[3]);


    std::thread t([&]() { io_service.run(); });

    connection.tryConnect();
    core.tryToConnect(connection, io_service);

    core.mainLoop(connection);
    io_service.stop();
    t.join();
    return 0;
}
