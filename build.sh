echo -e "\033[0;32mBuilding project...\033[0m"
cmake . .
cmake --build . --config Release
echo -e "\033[0;32mBuild complete!\033[0m"
exit 0