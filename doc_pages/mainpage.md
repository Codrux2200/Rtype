@mainpage

@section docu_sec Documentation

@subsection intro_sec Introduction

Welcome to the documentation of our @ref R-Type project.

This project aims at reproducing the R-Type game, a side-scrolling shoot-em-up game, in a networked environment.
Our repository contains both the server and the client to play the game.

This documentation contains everything you need to know about the project, from the installation to the usage of the client and server,
and even the @ref rfc_page "RFC" of the project if you want to implement your own client or server.



@subsection install_sec Installation

To install the game, you have to execute the installation script corresponding to your OS.

For Windows :
    
    ./install.bat

For Linux :
    
    sudo ./install.sh

Everything should install correctly, and you should be able to launch the game.

@subsection usage_sec Usage

First, you have to launch the server. To do so, you have to execute the server executable with the port you want to use as an argument:
    
    ./rtype-server 4242
    
Then, you can launch the client. To do so, you have to execute the client executable.
It takes three arguments:
- The IP address of the server
- The port of the server
- The name of the player
    
      ./client mysuperipaddress 4242 celestin


The first client to connect to the server becames the leader, and is the only one able to start the game.

If you are the leader, you can start a game by pressing the "Start" button.
Other players can connect to the server, and wait for the leader to start the game.

If the leader disconnects, the leadership changes to the next player connected.

## Once in game

You can move your ship with the arrow keys, and shoot with the space bar.

If you touch a monster, you die.
If you touch a bullet, you die.
If you touch a wall, you die.

Everytime you kill a monster, you gain 10 points.

@subsection contact_sec Contact

You can not contact us, we are dead.
