GREEN='\033[1;32m'
echo -e "${GREEN}Building with CMake..."

cmake . .
cmake --build . -- -j

echo -e "${GREEN}Build finished."
exit 0