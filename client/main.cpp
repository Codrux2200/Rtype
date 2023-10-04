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

int main(void)
{
    time_t t = time(nullptr);
    boost::asio::io_service io_service;
    Connection connection(io_service, "127.0.0.1", "4242");

    io_service.run();
    while (true) {
        if (time(nullptr) - t > 15000)
            break;
    }
    connection.quit();
    return 0;
}
