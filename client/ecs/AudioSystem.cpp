/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AudioSystem
*/

#include "AudioSystem.hpp"
#include "AudioComponent.hpp"
#include <vector>
#include <memory>

namespace ECS {
AudioSystem::AudioSystem() {
}

void AudioSystem::update(SceneManager &sceneManager, float /*deltaTime*/, std::vector<Network::Packet> &/*packetQueue*/, Network::PacketManager &/* packetManager*/) {
    for (auto entity : sceneManager.getCurrentScene()->entitiesList) {
        auto component = entity->getComponent<AudioComponent>();

        if(!component || !component->isEnabled())
            continue;
        if (!component->isPlaying()) {
            component->play();
        }
    }
}
}