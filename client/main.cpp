/*
** EPITECH PROJECT, 2023
** RType
** File description:
** main
*/

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include "Connection.hpp"
#include "Core.hpp"
#include "GraphicSystem.hpp"
#include "EventSystem.hpp"


int main(int ac, char **av)
{
    boost::asio::io_service io_service;
    RType::Connection connection(io_service, av[1], av[2], av[3]);
    ECS::Core core;

    std::thread t([&]() { io_service.run(); });

    core.mainLoop(connection);
    return 0;
}
