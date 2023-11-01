/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#pragma once

#include <SFML/Audio.hpp>
#include "AComponent.hpp"
#include <vector>
#include <memory>

namespace ECS {
class SoundComponent : public AComponent {
    public:
        SoundComponent() = default;
        ~SoundComponent() = default;
        SoundComponent(const SoundComponent& other);

        void play(const std::string& name);
        bool isPlaying(const std::string& name) const;
        [[nodiscard]] bool addSound(const std::string& name, std::string path);
        [[nodiscard]] std::shared_ptr<IComponent> clone() const override;
        void setVolume(std::string name, float volume);
        void setLoop(std::string name, bool loop);
        void stop(std::string name);
        void stopAll();
        float getVolume(std::string name);
        void setToBePlayed(std::string name, bool toBePlayed);

        void update();

    protected:
    private:
        struct Sound {
            std::shared_ptr<sf::Sound> sound;
            std::shared_ptr<sf::SoundBuffer> soundBuffer;
            bool hasToBePlayed = false;
        };
        std::unordered_map<std::string, Sound> _sounds;
    };
}

