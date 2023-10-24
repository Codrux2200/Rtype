/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#include "MusicComponent.hpp"
#include <iostream>

namespace ECS {
MusicComponent::MusicComponent(const MusicComponent& other) : _music(other._music)
{
}

MusicComponent::MusicComponent(std::shared_ptr<sf::Sound>) : _sound(_musicBuffer)
{
}


void MusicComponent::play()
{
    _music->play();
}

void MusicComponent::update()
{
    if (_music->getStatus() == sf::Music::Stopped) {
        // If the sound has finished playing, restart it
        _music->play();
    }
}

std::shared_ptr<IComponent> MusicComponent::clone() const
{
    return std::make_shared<MusicComponent>(*this);
}


bool MusicComponent::isPlaying() const
{
    return _music->getStatus() == sf::Music::Playing;
}
}