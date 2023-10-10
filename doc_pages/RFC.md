@page rfc_page RFC
@tableofcontents

@section intro_sec Introduction

This page contains the RFC of the R-Type project.

@section packet_sec Packet architecture

All the communication between the server and the client is done with packets.


@section server_connect_sec CONNECT

The server sends a CONNECT packet to all the clients when a new client is connected.

It will receive CONNECT from a client to accept a new connection.
If the server can't accept a new connection, the server will send back a CONNECT packet with the status set to @ref RFC::Status::KO "KO" only to the sender, with an appropriate message.

@section server_disconnect_sec DISCONNECT
