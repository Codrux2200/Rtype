for /f %%a in ('wmic cpu get NumberOfCores ^| findstr /r "[0-9]"') do (
    set "cores=%%a"
)

cmake -B build
cmake --build build --config Release -j %cores%

move build\Release\rtype-server.exe .
move build\Release\rtype-client.exe .

:end