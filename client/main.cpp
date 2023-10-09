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
#include "Core.hpp"

int main(int ac, char **av)
{
    boost::asio::io_service io_service;
    RType::Connection connection(io_service, av[1], av[2], av[3]);

    for (;;) {}
    return 0;
}
