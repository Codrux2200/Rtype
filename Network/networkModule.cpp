//
// Created by steph on 9/20/23.
//

#include "networkModule.hpp"

namespace network {

/////////////////// NetworkClient

    networkClient::networkClient(
        networkModule &parentModule,
        boost::asio::ip::udp::socket socket)
        : parentModule_(parentModule), socket_(std::move(socket))
        {}

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
        // Find the associated thread in the map and join it
        auto it = parentModule_.clientThreadMap.find(*this);
        if (it != parentModule_.clientThreadMap.end()) {
            it->second.join();
            parentModule_.clientThreadMap.erase(it);
        }

        // Remove the client from the list
        parentModule_.clients_.remove(*this);
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

        startAsyncReceive();
    }

    void networkModule::handleData(const paquet_t &data)
    {
        /// check paquet ids, stack paquets, etc
    }

    void networkModule::startAsyncReceive()
    {
        boost::asio::ip::udp::socket newSocket(ioContext_);
        listening_socket_.async_receive_from(
            boost::asio::buffer(rec_buffer_), remote_endpoint_,
            [this, newSocket](const boost::system::error_code& error, std::size_t bytes_received) {
                if (!error) {
                    networkClient client(*this, std::move(newSocket));
                    clients_.push_back(client); // Add to the clients container

                    // Start a new thread for the client
                    std::thread clientThread([this, &client]() {
                        client.start();
                    });

                    // Associate the thread with the client in the map
                    clientThreadMap.emplace(std::make_pair(client, std::move(clientThread)));
                }

                // Continue listening for the next client
                startAsyncReceive();
            }
        );
    }
} // namespace network
