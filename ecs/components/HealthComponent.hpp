/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** healthComponent
*/

#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Health component
     *
     */
    class HealthComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new health Component object
             *
             * @param health
             */
            HealthComponent(int health);
            /**
             * @brief Destroy the health Component object
             *
             */
            ~HealthComponent();
            /**
             * @brief Set the health of the entity
             *
             * @param health
             */
            void setValue(int health, int unused = 0) final;
            /**
             * @brief Get the health of the entity
             *
             * @return std::vector<int>
             */
            std::vector<int> getValue() const final;
        protected:
        private:
            int _health;
    };
}

#endif /* !HEALTHCOMPONENT_HPP_ */
