/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AudioComponent
*/

#ifndef AUDIOCOMPONENT_HPP_
#define AUDIOCOMPONENT_HPP_

#include <SFML/Audio.hpp>
#include <iostream>
#include "AComponent.hpp"

namespace ECS {
class AudioComponent : public AComponent{
public:
    AudioComponent(const AudioComponent& other);
    AudioComponent(std::string soundPath);
    ~AudioComponent() {
        _sound.stop();
        std::cout << "AudioComponent destructor" << std::endl;
    }
    void play();
    void update();
    bool isPlaying() const;
    std::shared_ptr<IComponent> clone() const override;


private:
    sf::SoundBuffer _soundBuffer;
    sf::Sound _sound;
};
}
#endif /* !AUDIOCOMPONENT_HPP_ */
