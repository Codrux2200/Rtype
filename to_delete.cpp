#include <boost/asio.hpp>
#include <iostream>

#define MAX_PLAYERS 4

using boost::asio::ip::udp;

namespace RType {
    class ClientManager {
        public:
            ClientManager();

            bool registerClient(
            const udp::endpoint &endpoint, const std::string &name);

        private:
            std::array<std::shared_ptr<Client>, MAX_PLAYERS> _clients;
    };

    class Client {
        public:
            Client(const udp::endpoint &endpoint, const std::string &name)
                : _last_activity(std::chrono::steady_clock::now()),
                  _endpoint(endpoint), _name(name) {};

        private:
            std::chrono::steady_clock::time_point _last_activity;
            udp::endpoint _endpoint;
            std::string _name;
    };
} // namespace RType

bool RType::ClientManager::registerClient(
const udp::endpoint &endpoint, const std::string &name)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (_clients[i] == nullptr) {
            _clients[i] = std::make_shared<Client>(endpoint, name);
            std::cout << "Client " << name << " connected" << std::endl;
            return true;
        }
    }
    return false;
}
