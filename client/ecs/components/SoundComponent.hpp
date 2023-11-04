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
#include <unordered_map>

namespace ECS {
/**
 * @brief Sound Component
 */
class SoundComponent : public AComponent {
    public:
        SoundComponent() = default;
        ~SoundComponent();
        /**
         * @brief Construct a new Sound Component object
         *
         * @param other the component to copy
         */
        SoundComponent(const SoundComponent& other);

        /**
         * @brief Play the sound
         * 
         * @param name the name of the sound
        */
        void play(const std::string& name);
        /**
         * @brief Get the sound status
         * 
         * @param name the name of the sound
         * @return bool true if the sound is playing
        */
        bool isPlaying(const std::string& name) const;
        /**
         * @brief Add a sound
         * 
         * @param name the name of the sound
         * @param path the path of the sound
         * @return true if the sound is added
        */
        [[nodiscard]] bool addSound(const std::string& name, std::string path);
        /**
         * @brief Clone the component
        */
        [[nodiscard]] std::shared_ptr<IComponent> clone() const override;
        /**
         * @brief Set the volume
         * 
         * @param name the name of the sound
         * @param volume the volume
        */
        void setVolume(std::string name, float volume);
        /**
         * @brief Set the loop
         * 
         * @param name the name of the sound
         * @param loop the loop
        */
        void setLoop(std::string name, bool loop);
        /**
         * @brief Stop the sound
         * 
         * @param name the name of the sound
        */
        void stop(std::string name);
        /**
         * @brief Stop all the sounds
        */
        void stopAll();
        /**
         * @brief Get the volume
         * 
         * @param name the name of the sound
         * @return float the volume
        */
        float getVolume(std::string name);
        /**
         * @brief Set the to be played
         * 
         * @param name the name of the sound
         * @param toBePlayed the to be played
        */
        void setToBePlayed(std::string name, bool toBePlayed);

        /**
         * @brief Update the sound
        */ 
        void update();

    protected:
    private:
        /**
         * @brief the sound structure
         * 
         * @param sound the sf::Sound
         * @param soundBuffer the sf::SoundBuffer
         * @param hasToBePlayed the bool to know has to be played
        */
        struct Sound {
            std::shared_ptr<sf::Sound> sound;
            std::shared_ptr<sf::SoundBuffer> soundBuffer;
            bool hasToBePlayed = false;
        };
        /**
         * @brief the sounds
        */
        std::unordered_map<std::string, Sound> _sounds;
    };
}

