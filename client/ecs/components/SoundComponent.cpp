/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SoundComponent
*/

#include "SoundComponent.hpp"
#include <iostream>

namespace ECS {

SoundComponent::SoundComponent(const SoundComponent &other)
    :_soundBuffer(other._soundBuffer), _sound(other._sound) {
}

SoundComponent::SoundComponent(std::string soundPath)
    :_sound(_soundBuffer) {
    if (_soundBuffer.loadFromFile("assets/sound/music.ogg")) {
        _sound.setBuffer(_soundBuffer);
    }
}

void SoundComponent::play() {
    _sound.play();
}

void SoundComponent::update() {
    if (_sound.getStatus() == sf::Sound::Stopped) {
        // If the sound has finished playing, restart it
        _sound.play();
    }
}


std::shared_ptr<IComponent> SoundComponent::clone() const {
    return std::make_shared<SoundComponent>(*this);
}
}

bool ECS::SoundComponent::isPlaying() const {
    return _sound.getStatus() == sf::Sound::Playing;
}
