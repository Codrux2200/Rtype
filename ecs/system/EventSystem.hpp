/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EventSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "ASystem.hpp"
#include "PositionComponent.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

namespace ECS {
    /**
     * @brief Event System
     * 
     */
    enum SFMLKeys {
        up = sf::Keyboard::Up,
        down = sf::Keyboard::Down,
        left = sf::Keyboard::Left,
        right = sf::Keyboard::Right,
        space = sf::Keyboard::Space,
        w = sf::Keyboard::W,
        a = sf::Keyboard::A,
        z = sf::Keyboard::Z,
        q = sf::Keyboard::Q,
        s = sf::Keyboard::S,
        d = sf::Keyboard::D,
    };
    class EventSystem : public ASystem{
        public:
            /**
             * @brief Construct a new Event System object
             * 
             */
            EventSystem();
            /**
             * @brief Destroy the Event System object
             * 
             */
            ~EventSystem();
            /**
             * @brief update the event system
             * 
             * @param sceneManager 
             * @param SceneType 
             * @param deltaTime 
             */
            void update(SceneManager &sceneManager, SceneType SceneType, int deltaTime) final;
        protected:
        private:
            /**
             * @brief Move the player
             * 
             * @param player
            */
            void _movePlayer(ECS::Entity *player);
            /**
             * @brief Move the player up and left
             * 
             * @param player
             * @param position
            */
            void _moveLeftUp(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player up and right
             * 
             * @param player
             * @param position
            */
            void _moveRightUp(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player down and left
             * 
             * @param player
             * @param position
            */
            void _moveLeftDown(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player down and right
             * 
             * @param player
             * @param position
            */
            void _moveRightDown(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player up
             * 
             * @param player
             * @param position
            */
            void _moveUp(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player down
             * 
             * @param player
             * @param position
            */
            void _moveDown(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player left
             * 
             * @param player
             * @param position
            */
            void _moveLeft(ECS::Entity *player, std::vector<int> position);
            /**
             * @brief Move the player right
             * 
             * @param player
             * @param position
            */
            void _moveRight(ECS::Entity *player, std::vector<int> position);
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
