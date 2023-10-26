/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SoundComponent
*/

#include "MusicsComponent.hpp"
#include <iostream>

namespace ECS {

MusicsComponent::MusicsComponent(const MusicsComponent &other)
    : _music(other._music) {
}

MusicsComponent::MusicsComponent(std::string soundPath)
{
    _music = std::make_shared<sf::Music>();

    if (!_music->openFromFile(soundPath)) {
        std::cerr << "Failed to load audio music file" << std::endl;
    }
}

void MusicsComponent::play() {
    _music->play();
    _music->setVolume(50);
}

void MusicsComponent::stop() {
    // Fade out the volume gradually
    while (_music->getVolume() > 1) {
        _music->setVolume(_music->getVolume() - 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Wait for 10 milliseconds
    }
    _music->stop();
}

void MusicsComponent::update() {
    if (_music->getStatus() == sf::Music::Stopped) {
        // If the sound has finished playing, restart it
        _music->play();
    }
}


std::shared_ptr<IComponent> MusicsComponent::clone() const {
    return std::make_shared<MusicsComponent>(*this);
}
}

bool ECS::MusicsComponent::isPlaying() const {
    return _music->getStatus() == sf::Music::Playing;
}
