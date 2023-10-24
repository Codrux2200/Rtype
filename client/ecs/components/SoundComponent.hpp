/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SoundComponent
*/

#ifndef SoundComponent_HPP_
#define SoundComponent_HPP_

#include <SFML/Audio.hpp>
#include <iostream>
#include "AComponent.hpp"

namespace ECS {
class SoundComponent : public AComponent{
public:
    SoundComponent(const SoundComponent& other);
    SoundComponent(std::string soundPath);
    ~SoundComponent() {
        _sound.stop();
        std::cout << "SoundComponent destructor" << std::endl;
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
#endif /* !SoundComponent_HPP_ */
