//
// Created by steph on 9/20/23.
//

#include "networkModule.hpp"

namespace network {

/////////////////// NetworkClient

    networkClient::networkClient(networkModule &parentModule, boost::asio::ip::udp::socket socket)
    {
        parentModule_ = std::move(parentModule);
        socket_ = std::move(socket);
    }

    void networkClient::start()
    {
        socket_.async_receive_from(boost::asio::buffer(rec_buffer_), remote_endpoint_,
            [this](const boost::system::error_code& error, std::size_t bytes_received) {
                if (!error) {
                    handleReceive(bytes_received);
                }
                start(); // Continue to receive more messages
            });
    }

    void networkClient::sendData(const std::string &data)
    {
    }

    void networkClient::handleReceive(std::size_t bytesReceived)
    {
    }

    void networkClient::close()
    {
        socket_.close();
        parentModule_.thread_map_[this].join()); // Jsp comment on use une map
    }

/////////////////// NetworkModule

    networkModule::networkModule()
    {
    }

    void networkModule::startAccept(const std::string& ip, int port)
    {
        boost::asio::ip::address ipAddr = boost::asio::ip::address::from_string(ip);
        endpoint_ = boost::asio::ip::udp::endpoint(ipAddr, port);
        boost::asio::ip::udp::endpoint senderEndpoint;
        boost::asio::ip::udp::socket temp(ioContext_);

        listening_socket_ = std::move(temp);
        listening_socket_.open(endpoint_.protocol());
        listening_socket_.bind(endpoint_);
        /// Quand le listening_socket recoit une connexion, il doit la balancer a un networkClient, dans un autre thread
    }

    void networkModule::handleData(const paquet_t &data)
    {
        /// check paquet ids, stack paquets, etc
    }
} // namespace network
