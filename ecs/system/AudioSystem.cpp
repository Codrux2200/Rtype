/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** AudioSystem
*/

#include "AudioSystem.hpp"

ECS::AudioSystem::AudioSystem()
{
}

ECS::AudioSystem::~AudioSystem()
{
}

bool ECS::AudioSystem::initAudio(std::string const &file)
{
    return true;
}

bool ECS::AudioSystem::isReady()
{
    return true;
}

float ECS::AudioSystem::getMainVolume()
{
    return _volume;
}


void ECS::AudioSystem::setVolume(float volume)
{
    _volume = volume;
}
