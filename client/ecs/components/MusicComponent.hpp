/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** MusicComponent
*/

#ifndef MUSICCOMPONENT_HPP_
#define MUSICCOMPONENT_HPP_

#include <SFML/Audio.hpp>
#include "AComponent.hpp"
#include <vector>
#include <memory>

namespace ECS {
class MusicComponent : public AComponent {
    public:
        MusicComponent(const MusicComponent& other);
        MusicComponent(std::shared_ptr<sf::Sound>);
        ~MusicComponent() = default;
        void play();
        void update();
        bool isPlaying() const;
        std::shared_ptr<IComponent> clone() const override;

    protected:
    private:
        sf::SoundBuffer _musicBuffer;
        sf::Sound _sound;
        std::shared_ptr<sf::Music> _music;
    };
}

#endif /* !MUSICCOMPONENT_HPP_ */
