/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AudioSystem
*/

#include "AudioSystem.hpp"
#include "MusicsComponent.hpp"
#include "SoundComponent.hpp"
#include <vector>
#include <memory>

namespace ECS {
AudioSystem::AudioSystem() {
}

void AudioSystem::update(SceneManager &sceneManager, float /*deltaTime*/, std::vector<Network::Packet> &/*packetQueue*/, Network::PacketManager &/* packetManager*/) {
    for (auto entity : sceneManager.getCurrentScene()->entitiesList) {
        auto component = entity->getComponent<MusicsComponent>();
        auto component2 = entity->getComponent<SoundComponent>();


        if(component && component->isEnabled()) 
            if (!component->isPlaying()) {
                component->play();
            }
        if(component2 && component2->isEnabled())
            if (component2->startPlaying == true) {
                component2->play();
                component2->startPlaying = false;
            }
        }
}
}