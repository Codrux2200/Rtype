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
    RType::Server server(io_service, 4242);
    ECS::ServerCore serverCore(server);

    std::srand(std::time(nullptr));
    std::cout << "Hello, I'm the server!" << std::endl;
    std::cout << "Size of Packet: " << sizeof(Network::Packet) << std::endl;
    std::thread t([&io_service]() { io_service.run(); });
    serverCore.mainLoop();
    return 0;
}
