/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AudioComponent
*/

#include "AudioComponent.hpp"
#include <iostream>

namespace ECS {

AudioComponent::AudioComponent(const AudioComponent &other)
    :_soundBuffer(other._soundBuffer), _sound(other._sound) {
}

AudioComponent::AudioComponent(std::string soundPath)
    :_sound(_soundBuffer) {
    if (_soundBuffer.loadFromFile("assets/sound/music.ogg")) {
        _sound.setBuffer(_soundBuffer);
    }
}

void AudioComponent::play() {
    _sound.play();
}

void AudioComponent::update() {
    if (_sound.getStatus() == sf::Sound::Stopped) {
        // If the sound has finished playing, restart it
        _sound.play();
    }
}


std::shared_ptr<IComponent> AudioComponent::clone() const {
    return std::make_shared<AudioComponent>(*this);
}
}

bool ECS::AudioComponent::isPlaying() const {
    return _sound.getStatus() == sf::Sound::Playing;
}
