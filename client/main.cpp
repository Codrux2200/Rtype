/*
** EPITECH PROJECT, 2023
** RType
** File description:
** main
*/

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include "Connection.hpp"

int main(int ac, char **av)
{
    time_t t = time(nullptr);
    boost::asio::io_service io_service;
    RType::Connection connection(io_service, av[1], av[2], av[3]);

    io_service.run();
    while (true) {
        if (time(nullptr) - t > 15000)
            break;
    }
    connection.quit();
    return 0;
}
