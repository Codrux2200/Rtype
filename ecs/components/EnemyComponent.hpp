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
            EnemyComponent();
            /**
             * @brief Destroy the enemy Component object
             *
             */
            ~EnemyComponent();
            /**
             * @brief Set the enemy of the entity
             *
             * @param enemy
             */
            void setValue(std::vector<int> values) final;
            /**
             * @brief Get the enemy of the entity
             *
             * @return std::vector<int>
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
