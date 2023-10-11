/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** shootComponent
*/

#ifndef SHOOTCOMPONENT_HPP_
#define SHOOTCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Shoot component
     *
     */
    class ShootComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new shoot Component object
             *
             * @param uid
             */
            ShootComponent(int shootSpeed, int shootDamage);
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
            void setValue(int shootSpeed, int shootDamage) final;
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
    };
}

#endif /* !SHOOTCOMPONENT_HPP_ */
