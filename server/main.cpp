/*
** EPITECH PROJECT, 2023
** RType
** File description:
** main
*/

#include "Packet.hpp"
#include "Server.hpp"

int main(void)
{
    boost::asio::io_service io_service;

    std::cout << "Hello, I'm the server!" << std::endl;
    std::cout << "Size of Packet: " << sizeof(Network::Packet) << std::endl;
    RType::Server server(io_service, 4242);
    io_service.run();
    return 0;
}
