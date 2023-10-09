/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** AudioSystem
*/

#include "AudioSystem.hpp"

ECS::AudioSystem::AudioSystem()
{
    typeSystem = ECS::SystemType::AUDIO;
}

ECS::AudioSystem::~AudioSystem()
{
}

bool ECS::AudioSystem::initAudio(std::string const &file)
{
    _filePath = file;
}

bool ECS::AudioSystem::isReady()
{

}

float ECS::AudioSystem::getMainVolume()
{
    return _volume;
}


void ECS::AudioSystem::setVolume(float volume)
{
    _volume = volume;
}




