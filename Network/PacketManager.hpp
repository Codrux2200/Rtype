/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PacketManager
*/

#pragma once

#include <map>
#include <memory>
#include <functional>
#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include "Packet.hpp"

/**
 * @brief The size of a packet in bytes.
 * It is used to store the bytes of a packet in a char array.
 * It is also used to send the size of the packet to the server, and to
 * determine if the packet is complete or not.
 */
#define PACKET_SIZE 36

/**
 * @brief Macro used to register a handler for a packet type.
 * it passes the handler to the PacketManager::registerHandler method, and
 * binds the handler to the current object so it can be called.
 *
 */
#define REGISTER_HANDLER(type, handler) \
    registerHandler(type, std::bind(handler, this, std::placeholders::_1, std::placeholders::_2));

using boost::asio::ip::udp;

namespace Network {

    /**
     * @brief A PacketManager have to be used both on the client and the server
     * side. It is used to create, handle and convert packets.
     *
     */
    class PacketManager {
        public:
            /**
             * @brief Construct a new PacketManager object
             *
             */
            PacketManager() = default;
            /**
             * @brief Destroy the PacketManager object
             */
            ~PacketManager() = default;

            /**
             * @brief Create a packet. It is used to create a packet to send.
             *
             * @param type The type of the packet
             * @param data The data to put in the packet. Be careful, the
             * PacketType determines the type of the data. See
             * Network::PacketType and Network::data for more information.
             * @return std::unique_ptr<Network::Packet> The packet created
             *
             * @see Network::Packet
             * @see Network::PacketType
             * @see Network::data
             */
            static std::unique_ptr<Packet> createPacket(
            PacketType type, void *data = nullptr);

            /**
             * @brief Convert a packet to a char array. It is used to send
             * packets in bytes.
             *
             * @param packet The packet to convert
             * @return std::vector<char> The char array created
             *
             * @see Network::Packet
             */
            static std::vector<char> packetToBytes(const Packet &packet);

            /**
             * @brief Convert a char array to a packet. It is used to convert
             * the received bytes to a packet.
             *
             * @param bytes The char array to convert
             * @param bytes_size The size of the char array
             * @return std::unique_ptr<Network::Packet> The packet created
             *
             * @see Network::Packet
             */
            static std::unique_ptr<Packet> bytesToPacket(
            const char *bytes, std::size_t bytes_size);

            /**
             * @brief Register a handler for a packet type. The handler will be
             * called when a packet of the specified type is received.
             *
             * @param type
             * @param handler
             */
            void registerHandler(
            PacketType type, std::function<void(Packet &, const udp::endpoint &)> handler);

            /**
             * @brief Used to handle a packet. It will call the handler
             * associated to the packet type.
             *
             * @param packet The packet to handle
             *
             * @see Network::Packet
             */
            void handlePacket(Packet &packet, udp::endpoint &endpoint);

            /**
             * @brief Add a packet to the receive queue. It will be handled when
             * the PacketManager::executeRecvPacketsQueue method is called.
             * @param packet
             * @param endpoint
             */
            void addPacketToRecvQueue(Packet &packet, const udp::endpoint &endpoint);

            /**
             * @brief Handle all the packets in the receive queue.
             */
            void executeRecvPacketsQueue();

            /**
             * @brief The send queue. It contains all the packets to send.
             */
            std::vector<Packet> sendPacketsQueue;
            /**
             * @brief The receive queue.
             *
             */
            std::vector<std::pair<udp::endpoint, Packet>> recvPacketsQueue;

            std::mutex mutex;
        private:
            /**
             * @brief A map that contains all the handlers for each packet type.
             * The key is the packet type, and the value is the handler.
             * Use registerHandler method to add a handler.
             */
            std::map<PacketType, std::function<void(Packet &, const udp::endpoint &)>> _handlers;
    };
} // namespace Network
