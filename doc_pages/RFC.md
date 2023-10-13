@page rfc_page RFC
@tableofcontents

@section intro_sec Introduction

This page contains the RFC of the R-Type project.

@section packet_sec Packet architecture

The Packet serves as the primary unit of communication between the client and the server.
It encompasses the following members:

- @b type: Specifies the type of the packet. It is of type PacketType.
- @b connectData: Contains data pertinent to connection operations. It is of type ConnectData.
- @b disconnectData: Holds data related to disconnection procedures. It is of type ConnectData.
- @b startData: Stores data regarding the commencement of a session or game. Type: StartData.
- @b joinData: Contains data about joining an ongoing session or game. Type: JoinData.
- @b leaderData: Indicates the leader within a session or game context. Type: LeaderData.
- @b moveData: Relates to movement operations. Type: MoveData.

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
