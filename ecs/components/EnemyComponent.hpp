/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_
#include <SFML/Graphics.hpp>
#include <string>
#include "AComponent.hpp"

namespace ECS {
    /**
     * @brief Enemy component
     * 
     */
    class EnemyComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new enemy Component object
             * 
             * @param uid 
             */
            EnemyComponent(int uid, const std::string &spritePath);
            /**
             * @brief Destroy the enemy Component object
             * 
             */
            ~EnemyComponent();
            /**
             * @brief Set the sprite path for the player entity
             *
             * @param newSpritePath The path to the new sprite image
             */
            void setSprite(const std::string& newSpritePath);
            /**
             * @brief Get the sprite path for the player entity
             *
             * @return std::string
             */
            std::string getSprite() const;
            /**
             * @brief Update the component
             * 
             * @param positions the vector of the positions of the entity
             */
            void update(const std::vector<int> positions);
            /**
             * @brief Draw the components
             * 
             * @param window the renderWindow
            */
            void draw(sf::RenderWindow &window);
        protected:
        private:
            std::string _spritePath;
            std::unique_ptr<sf::Sprite> _sprite;
            sf::Texture _texture;
    };
}

#endif /* !ENEMYCOMPONENT_HPP_ */
