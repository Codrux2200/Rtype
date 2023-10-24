/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#include "SoundComponent.hpp"
#include <iostream>

namespace ECS {
SoundComponent::SoundComponent(const SoundComponent& other) : _sounds(other._sounds)
{
}

SoundComponent::SoundComponent(std::shared_ptr<sf::Sound>)
{
}


void SoundComponent::play()
{
    _sounds->play();
}

void SoundComponent::update()
{
    if (_sounds->getStatus() == sf::Music::Stopped) {
        // If the sound has finished playing, restart it
        _sounds->play();
    }
}

std::shared_ptr<IComponent> SoundComponent::clone() const
{
    return std::make_shared<SoundComponent>(*this);
}


bool SoundComponent::isPlaying() const
{
    return _sounds->getStatus() == sf::Music::Playing;
}
}