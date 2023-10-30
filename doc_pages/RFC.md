@page rfc_page RFC
@tableofcontents

#### Welcome to our R-Type's Request For Comments (RFC) page.
#### This page contains all the information you need to know about the communication between the client and the server.


@section packet_sec Packet architecture

The Packet serves as the primary unit of communication between the client and the server.
It encompasses the following members:

- @b type: Specifies the type of the packet. It is of type PacketType.
- @b data [Optional]: A union of all the possible data types that can be sent. It can be of type ConnectData, DisconnectData, StartData, JoinData, LeaderData, MoveData.

The data union can be of the following types:

- @b connectData: Contains data pertinent to connection operations. It is of type ConnectData.
- @b disconnectData: Holds data related to disconnection procedures. It is of type ConnectData.
- @b startData: Stores data regarding the commencement of a game. Type: StartData.
- @b joinData: Contains data about joining a session. Type: JoinData.
- @b leaderData: Indicates the leader within a session or game context. Type: LeaderData.
- @b moveData: Relates to movement operations. Type: MoveData.

Each are precised in the following sections.

@section packet_types_sec Packet types

@ref diag_ex "Example of a connexion between a client and a server"


@subsection server_rfc_sec Server packets

@subsubsection server_connect_sec CONNECT

A client sends a CONNECT packet to the server it wants to connect to.

The server sends a CONNECT packet to all the clients when a new client is connected.
If the server can't accept a new connection, the server will send back a CONNECT packet with the status set to @ref RFC::Status::KO "KO" to the client, with an appropriate message.

The CONNECT packet contains an array of MAX_PLAYERS (currently 4) size, containing char (1 byte) arrays of NAME_LENGTH (currently 7), which contains the names of the players connected.

  @ref Network::data::ConnectData

@subsubsection server_disconnect_sec DISCONNECT

The server sends a DISCONNECT packet to all the clients when a client wants to @ref server_quit_sec "quit".

A DISCONNECT packet contains only 1 char (1 byte), which is the id of the player that disconnected.

  @ref Network::data::ConnectData

@subsubsection server_start_sec START

When the game Leader client sends a START packet, the server will send a START packet to all the clients to start the game.

Start packet contains a short of 2 bytes, which is the id of the game map.

  @ref Network::data::StartData



@subsubsection client_dead_sec DEAD

When a player dies, the server sends a DEAD packet to the clients.
The packet contains a char (1 byte), which is the id of the player that died.


@subsubsection server_join_sec JOIN

When a client wants to join a game, it sends a JOIN packet to the server.
The packet contains a NAME_LENGTH char (1 byte) array, which is the name of the player that joins.
NAME_LENGTH is defined JoinData.hpp (currently set to 7, so 7 bytes).

  @ref Network::data::JoinData

@subsubsection server_move_sec MOVE

A client sends a MOVE packet to the server to communicate the position of its player.
The packet contains a byte for the id of the player, and two int (4 bytes) corresponding to the X and Y position

  @ref Network::data::MoveData


@subsubsection server_sht_sec SHOOT

When a player shoots, the client sends a SHOOT packet to the server.
The server then sends a SHOOT packet to all the clients.
The packet contains a char (1 byte), which is the id of the shooting player.


@subsubsection server_hit_sec HIT

When a player is hit or hits a monster, the server sends a HIT packet to all the clients.
The packet contains a NAME_LENGTH char (1 byte) array, which is the name of the concerned player, or monster.


@subsubsection server_score_sec SCORE

When the score changes, the server sends a SCORE packet to all the clients.
The packet contains an int (4 bytes), which is the new score for everyone.

@subsubsection server_espwn_sec ENTITY_SPAWN

When an enemy spawns, the server sends an ENTITY_SPAWN packet to all the clients.
The packet contains a char (1 byte), which is the id of the enemy that spawned,
and two int (4 bytes) corresponding to the X and Y position of the enemy.

@subsubsection server_eded_sec ENEMY_DEAD

When an enemy is dead, the server sends an ENEMY_DEAD packet to all the clients.
The packet contains a char (1 byte), which is the id of the enemy that died.

@subsubsection server_emve_sec ENEMY_MOVE

the server sends a MOVE packet to clients to communicate the position of an enemy.
The packet contains a byte for the id of the enemy, and two int (4 bytes) corresponding to the X and Y position

  @ref Network::data::MoveData

@subsubesction server_esht_sec ENEMY_SHOOT

When an enemy shoots, the server sends an ENEMY_SHOOT packet to all the clients.
The packet contains a char (1 byte), which is the id of the enemy that shot.


@subsubsection server_elife_sec ENEMY_LIFE

When an enemy's life changes, the server sends an ENEMY_LIFE packet to all the clients.
The packet contains a char (1 byte), which is the id of the enemy that changed life,
and an int (4 bytes) corresponding to the new life of the enemy.

@subsubsection server_map_sec MAP

When a map object is created or modified, the server sends a MAP packet to all the clients.
The packet contains a char (1 byte), which is the id of the map object,
and two int (4 bytes) corresponding to the X and Y position of the map object.

@subsubsection server_end_sec END

When the game ends, the server sends an END packet to all the clients.
It does not contain any data.

@subsubsection server_leader_sec LEADER

The server sends a LEADER packet to all the clients at client connexion, or when the leader of the game changes.
The packet contains a char (1 byte), which is the id of the leader.

  @ref Network::data::LeaderData

@subsection client_rfc_sec Client packets

@subsubsection client_connect_sec CONNECT

-> See the @ref server_connect_sec "CONNECT" packet.

@subsubsection client_start_sec START

-> See the @ref server_start_sec "START" packet.

@subsubsection client_move_sec MOVE

-> See the @ref server_move_sec "MOVE" packet.

@subsubsection client_sht_sec SHOOT

-> See the @ref server_sht_sec "SHOOT" packet.

@subsubsection client_quit_sec QUIT

When a client wants to quit a game, it sends a QUIT packet to the server.
The server then sends a @ref server_disconnect_sec "DISCONNECT" packet to all the clients.
It does not contain any data.

@subsection diag_ex Example of a connexion between a client and a server

@image html sequence_diag.png "Sequence diagram of a connexion between a client and a server"

### Explanations:

- The client sends a CONNECT packet to the server.
- The server sends a CONNECT packet to all the clients (Only one at the moment).
- The server sends a LEADER packet to all the clients (Only one at the moment).

- The new client sends a CONNECT packet to the server.
- The server sends a CONNECT packet to all the clients.

- The leader client sends a START packet to the server.
- The server sends a START packet to all the clients.

- The leader client sends a QUIT packet to the server.
- The server sends a DISCONNECT packet to all the clients.

- The server sends a LEADER packet to the only remaining client.
- The client sends a START packet to the server.
- The server sends a START packet to all the clients (Only one at the moment).
