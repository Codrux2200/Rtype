/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
    #define ISYSTEM_HPP_

#include "SceneManager.hpp"
#include "Packet.hpp"
#include "PacketManager.hpp"

namespace ECS
{
    /**
     * @brief ISystem class
     *
     */
    class ISystem {
        public :
            /**
             * @brief update all the system
             *
             * @param sceneManager
             * @param deltaTime
             */
            virtual void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue, Network::PacketManager &packetManager) = 0;
    };
} // namespace ECS


#endif /* !ISystem_HPP_ */
