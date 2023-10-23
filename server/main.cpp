/*
** EPITECH PROJECT, 2023
** RType
** File description:
** main
*/

#include <thread>
#include "Packet.hpp"
#include "Server.hpp"
#include "ServerCore.hpp"

int main()
{
    boost::asio::io_service io_service;
    ECS::ServerCore serverCore;

    std::srand(std::time(nullptr));
    std::cout << "Hello, I'm the server!" << std::endl;
    std::cout << "Size of Packet: " << sizeof(Network::Packet) << std::endl;
    RType::Server server(io_service, 4242);
    std::thread t([&io_service]() { io_service.run(); });
    serverCore.mainLoop(server);
    return 0;
}
