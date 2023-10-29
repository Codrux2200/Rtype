/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AudioSystem
*/


#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ISystem.hpp"
namespace ECS {

class AudioSystem : public ISystem {
    public:
        AudioSystem() = default;

        void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;

    protected:
    private:
};
}
#endif /* !AUDIOSYSTEM_HPP_ */
