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

namespace ECS {

void AudioSystem::update(SceneManager &sceneManager, float /*deltaTime*/, std::vector<Network::Packet> &/*packetQueue*/)
{
    for (auto entity : sceneManager.getCurrentScene()->entitiesList) {
        auto component = entity->getComponent<MusicsComponent>();
        auto component2 = entity->getComponent<SoundComponent>();

        if (component && component->isEnabled)
            if (!component->isPlaying()) {
                component->play();
            }
        if (component2 && component2->isEnabled) {
            if (component2->startPlaying) {
                component2->play();
                component2->startPlaying = false;
            }
        }
    }
}
}