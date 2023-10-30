cmake -B build
cmake --build build --config Release -j %cores%

move build\Release\rtype-server.exe .
move build\Release\rtype-client.exe .

:end
