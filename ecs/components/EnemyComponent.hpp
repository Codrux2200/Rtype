/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_
#include "Acomponent.hpp"

namespace ECS {
    class EnemyComponent : public ECS::Acomponent {
        public:
            /**
             * @brief Construct a new enemy Component object
             * 
             * @param uid 
             */
            EnemyComponent(int uid);
            /**
             * @brief Destroy the enemy Component object
             * 
             */
            ~EnemyComponent();
        protected:
        private:
    };
}

#endif /* !ENEMYCOMPONENT_HPP_ */
