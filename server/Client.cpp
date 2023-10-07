/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Client
*/

#include "Client.hpp"

const udp::endpoint &RType::Client::getEndpoint() const
{
    return _endpoint;
}

void RType::Client::setLastActivity(std::chrono::steady_clock::time_point time)
{
    _last_activity = time;
}

const std::chrono::steady_clock::time_point &
RType::Client::getLastActivity() const
{
    return _last_activity;
}

const std::string &RType::Client::getName() const
{
    return _name;
}

void RType::Client::setLeader(bool lead)
{
    _isLeader = lead;
}

bool RType::Client::isLeader(void) const
{
    return _isLeader;
}

bool RType::Client::operator==(const Client &rhs) const
{
    return _endpoint == rhs._endpoint;
}
