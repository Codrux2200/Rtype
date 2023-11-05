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
    /**
     * @brief Construct a new Musics Component object
     *
     * @param other the component to copy
     */
    MusicsComponent(const MusicsComponent& other);
    /**
     * @brief Construct a new Musics Component object
     *
     * @param soundPath the sound path
     */
    MusicsComponent(std::string soundPath);
    ~MusicsComponent() = default;
    
    /**
     * @brief Play the sound 
     *
     */
    void play();
    /**
     * @brief Stop the sound
     *
     */
    void stop();
    /**
     * @brief Update the sound
     *
     */
    void update();
    /**
     * @brief Get the music status
     *
     * @return bool true if the sound is playing
     */
    bool isPlaying() const;
    /**
     * @brief Clone the component
     *
     */
    std::shared_ptr<IComponent> clone() const override;


private:
    /**
     * @brief the sound
     *
     */
    std::shared_ptr<sf::Music> _music;
};
}
#endif /* !Musics_Component_HPP_ */
