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
    :_musicsBuffer(other._musicsBuffer), _musics(other._musics) {
}

MusicsComponent::MusicsComponent(std::string soundPath)
    :_musics(_musicsBuffer) {
    if (_musicsBuffer.loadFromFile("assets/sound/music.ogg")) {
        _musics.setBuffer(_musicsBuffer);
    }
}

void MusicsComponent::play() {
    _musics.play();
}

void MusicsComponent::update() {
    if (_musics.getStatus() == sf::Sound::Stopped) {
        // If the sound has finished playing, restart it
        _musics.play();
    }
}


std::shared_ptr<IComponent> MusicsComponent::clone() const {
    return std::make_shared<MusicsComponent>(*this);
}
}

bool ECS::MusicsComponent::isPlaying() const {
    return _musics.getStatus() == sf::Sound::Playing;
}
