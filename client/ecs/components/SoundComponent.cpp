/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#include <iostream>
#include "ConvertPath.hpp"
#include "SoundComponent.hpp"

namespace ECS {
    SoundComponent::SoundComponent(const SoundComponent& other) : _sounds(other._sounds)
    {
    }

    void SoundComponent::play(const std::string& name)
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return;
        }
        _sounds.at(name).sound->play();
    }


    std::shared_ptr<IComponent> SoundComponent::clone() const
    {
        return std::make_shared<SoundComponent>(*this);
    }


    bool SoundComponent::isPlaying(const std::string& name) const
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return false;
        }
        return _sounds.at(name).sound->getStatus() == sf::Sound::Playing;
    }

    bool SoundComponent::addSound(const std::string& name, std::string path)
    {
        if (_sounds.find(name) != _sounds.end()) {
            std::cerr << "Sound " << name << " already exists" << std::endl;
            return false;
        }
        _sounds[name].soundBuffer = std::make_shared<sf::SoundBuffer>();
        if (!_sounds[name].soundBuffer->loadFromFile(ConvertPath::convertPath(path))) {
            std::cerr << "Error loading sound " << name << std::endl;
            return false;
        }
        _sounds[name].sound = std::make_shared<sf::Sound>(*_sounds[name].soundBuffer);
        return true;
    }

    void SoundComponent::setVolume(std::string name, float volume)
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return;
        }
        _sounds.at(name).sound->setVolume(volume);
    }

    void SoundComponent::setLoop(std::string name, bool loop)
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return;
        }
        _sounds.at(name).sound->setLoop(loop);
    }

    void SoundComponent::stop(std::string name)
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return;
        }
        _sounds.at(name).sound->stop();
    }

    void SoundComponent::stopAll()
    {
        for (auto &sound : _sounds)
            sound.second.sound->stop();
    }

    float SoundComponent::getVolume(std::string name)
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return 0;
        }
        return _sounds.at(name).sound->getVolume();
    }

    void SoundComponent::setToBePlayed(std::string name, bool toBePlayed)
    {
        if (_sounds.find(name) == _sounds.end()) {
            std::cerr << "Sound " << name << " not found" << std::endl;
            return;
        }
        _sounds.at(name).hasToBePlayed = toBePlayed;
    }

    void SoundComponent::update()
    {
        for (auto &sound : _sounds) {
            if (sound.second.hasToBePlayed) {
                sound.second.sound->play();
                sound.second.hasToBePlayed = false;
            }
        }
    }
}