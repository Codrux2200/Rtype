
# R-TYPE

Epitech 2025 end year project



## Summary

- The project

- Server

- Client

- Prerequisites

- Installing 

- Usage

# The project

The project is a rtype game with the possibility to connect multiple players and let them interact with each other in one same game.


# Server

Using [Boost/Asio](https://www.boost.org/doc/libs/1_83_0/doc/html/boost_asio.html) the server receive the client inputs and treat the data in his different systems and re-send the actualized sprite.


```for exemple a a client thread will send movement information to the server socket who will be sending back the actualized position of this client to the other ones```



## Client

The client part is where the gameloop mostly run, it's goal is too init and load all the graphic before the server take and update them.
## Prerequisites

Requirements for the software and other tools to build, test and push

- Visual Studio (Windows)
- GCC (Linux)

## Installing

On Linux:
- simply run install.sh with this :```sudo ./install.sh```

On Windows:

- run this the Install_windows.bat : ```$>Install_windows.bat```

## Usage

On Linux:
- run : ```./build.sh```

On Windows :
- run : ``` $> Build_Windows.bat```

after building you will have to run two terminal

in the first one:
- run : ```./server/bin/rtype_server(.exe) [port]``` without ```./``` on cmd.

in the second one:
- run : ``` ./client/bin/rtype_client(.exe) [ip] [port] [pseudonyme]``` without ```./``` on cmd.

## Tech Stack

**Client:** C++, Sfml, Boost/Asio

**Server:** C++, Sfml, Boost/Asio


## Authors

- [Leo Maman](https://github.com/mangasteak)
- [Raphael Mercier](https://github.com/raphaelMrci)
- [Saad Berrada](https://github.com/Codrux2200)
- [Christophe Chors](https://github.com/christophechr)
- [Stephane Corbière](https://github.com/STCB)
