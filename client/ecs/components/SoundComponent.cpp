/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#include "SoundComponent.hpp"
#include <iostream>

namespace ECS {
SoundComponent::SoundComponent(const SoundComponent& other) : _sounds(other._sounds), _soundBuffer(other._soundBuffer)
{
}

SoundComponent::SoundComponent(std::shared_ptr<sf::Sound> sounds, std::shared_ptr<sf::SoundBuffer> soundbuffer) : _sounds(sounds), _soundBuffer(soundbuffer)
{
}


void SoundComponent::play()
{
    _sounds->play();
}


std::shared_ptr<IComponent> SoundComponent::clone() const
{
    return std::make_shared<SoundComponent>(*this);
}


bool SoundComponent::isPlaying() const
{
    return _sounds->getStatus() == sf::Sound::Playing;
}
}