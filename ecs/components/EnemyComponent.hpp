/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_
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
             * @brief Get the enemy of the entity
             *
             * @return std::vector<int>
             */
            void update(const std::vector<int> positions);
            /**
             * @brief clone the component
             *
             * @return std::shared_ptr<IComponent>
             */
            std::shared_ptr<IComponent> clone() const override;
        protected:
        private:
    };
}

#endif /* !ENEMYCOMPONENT_HPP_ */
