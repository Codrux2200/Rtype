/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#ifndef SOUNDCOMPONENT_HPP_
#define SOUNDCOMPONENT_HPP_

#include <SFML/Audio.hpp>
#include "AComponent.hpp"
#include <vector>
#include <memory>

namespace ECS {
class SoundComponent : public AComponent {
    public:
        SoundComponent(const SoundComponent& other);
        SoundComponent(std::shared_ptr<sf::Sound>, std::shared_ptr<sf::SoundBuffer>);
        ~SoundComponent() = default;
        void play();
        bool isPlaying() const;
        bool startPlaying= true;
        std::shared_ptr<IComponent> clone() const override;

    protected:
    private:
        std::shared_ptr<sf::SoundBuffer> _soundBuffer;
        std::shared_ptr<sf::Sound> _sounds;
    };
}

#endif /* !SOUNDCOMPONENT_HPP_ */
