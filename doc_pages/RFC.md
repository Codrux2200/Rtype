@page rfc_page RFC
@tableofcontents

@section intro_sec Introduction

This page contains the RFC of the R-Type project.

@section packet_sec Packet architecture

All the communication between the server and the client is done with packets.

A packet is composed of 3 parts :

-   @ref RFC::Packet::id "long int id" : The unique identifier of the packet
-   @ref RFC::Packet::sequence "int sequence" : The sequence of the packet
-   @ref RFC::Packet::replication "short replication" : The replication of the packet
-   @ref RFC::Packet::timestamp "std::time_t timestamp" : The timestamp of the packet
-   @ref RFC::Packet::message "char message[256]" : The message of the packet
-   @ref packet_types_sec "PacketType type" : The type of the packet
-   @ref packet_types_sec "Status status" : The status of the packet
-   @ref RFC::data "RFC::data data" : The data of the packet

Each type of packet has a different data structure.

@see RFC::Status
@see RFC::PacketType
@see RFC::data

@section packet_types_sec Packet types

@subsection server_rfc_sec Server

@subsubsection server_connect_sec CONNECT

The server sends a CONNECT packet to all the clients when a new client is connected.

It will receive CONNECT from a client to accept a new connection.
If the server can't accept a new connection, the server will send back a CONNECT packet with the status set to @ref RFC::Status::KO "KO" only to the sender, with an appropriate message.

@subsubsection server_disconnect_sec DISCONNECT

@see RFC
