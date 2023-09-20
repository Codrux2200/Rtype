//
// Created by steph on 9/20/23.
//

#ifndef PUBRTYPE_NETWORKMODULE_HPP
#define PUBRTYPE_NETWORKMODULE_HPP

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <queue>
#include <unordered_map>

struct paquet_t {
};

namespace network {

    class networkModule;

    class networkClient {
    public:
        // Constructor for a networkClient, takes a reference to the networkModule
        // parentModule pour appeler la fonction handleData, et clore le thread en cas de close()
        networkClient(networkModule &parentModule, boost::asio::ip::udp::socket socket);

        // Method to start handling the client's connection
        void start();

        // Method to send data to the client
        void sendData(const std::string& data);

        void handleReceive(std::size_t bytesReceived);

        // Method to close the client's connection
        void close();

    private:
        networkModule& parentModule_; // Reference to the parent networkModule
        boost::asio::ip::udp::socket socket_;
        boost::array<char, 1024> rec_buffer_;
        boost::asio::ip::udp::endpoint remote_endpoint_;
    };

    class networkModule {
    public:
        networkModule();

        // Method to start listening for incoming client connections
        void startAccept(const std::string& ip, int port);

        void handleData(const paquet_t &data);

        std::unordered_map<networkClient, std::thread> thread_map_; // probleme ?
    private:
        boost::asio::io_context &ioContext_;
        boost::asio::ip::udp::socket listening_socket_;
        boost::asio::ip::udp::endpoint endpoint_;
        std::queue<networkClient> clients_;
        std::queue<paquet_t> paquet_queue_;
    };

} // namespace network

#endif // PUBRTYPE_NETWORKMODULE_HPP
