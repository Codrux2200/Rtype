/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** SoundComponent
*/

#ifndef Musics_Component_HPP_
#define Musics_Component_HPP_

#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include "AComponent.hpp"

namespace ECS {
class MusicsComponent : public AComponent{
public:
    MusicsComponent(const MusicsComponent& other);
    MusicsComponent(std::string soundPath);
    ~MusicsComponent() = default;
    void play();
    void stop();
    void update();
    bool isPlaying() const;
    std::shared_ptr<IComponent> clone() const override;


private:
    std::shared_ptr<sf::Music> _music;
};
}
#endif /* !Musics_Component_HPP_ */
