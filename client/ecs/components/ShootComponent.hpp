/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** shootComponent
*/

#ifndef SHOOTCOMPONENT_HPP_
#define SHOOTCOMPONENT_HPP_
#include "AComponent.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include "EntityFactory.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"
#include "SFML/Graphics.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    /**
     * @brief Shoot component
     *
     */
    class ShootComponent : public ECS::AComponent {
        public:
            /*
             * @brief The type of the shoot
             * A type for each kind of shoot needed.
             */
            enum ShootType {
                NORMAL,
                BIG,
                REVERSE,
                DICK
            };
            /**
             * @brief Construct a new shoot Component object
             *
             * @param shootSpeed
             * @param shootDamage
             * @param type
             */
            ShootComponent(int shootSpeed, int shootDamage, ShootType type);
            /**
             * @brief Destroy the shoot Component object
             *
             */
            ~ShootComponent();
            /**
             * @brief Get the Shoot Speed and the shoot damage of the entity
             *
             * @return std::vector<int>
             */
            std::vector<int> getValue() const final;
            /**
             * @brief Set the Shoot Speed and the shoot damage of the entity
             *
             * @param shootSpeed
             * @param shootDamage
             */
            void setValue(std::vector<int> values) final;
            /*
             * @brief generate a new shot entity and adds it to the queue
             */
            void newShot(std::vector<int> pos);
            /*
             * @brief move all the shots in the queue
             */
            void moveShots(void);

        protected:
        private:
            /**
             * @brief define the shoot speed of the entity
             *
             */
            int _shootSpeed;
            /**
             * @brief define the shoot damage of the entity
             *
             */
            int _shootDamage;
            /**
             * @brief define a shot queue for the entity,
             * containing all the shots entities
             */
            std::vector<ECS::Entity> _shots;
            /*
             * @brief The shoot factory
             * Each entity with a shootcomponent benefeciate its own factory
             * A bit overkill maybe, but necessary with the ECS design.
             */
            ECS::EntityFactory _factory;
    };
}

#endif /* !SHOOTCOMPONENT_HPP_ */
