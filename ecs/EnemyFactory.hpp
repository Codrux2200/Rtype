/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyFactory
*/

#ifndef ENEMYFACTORY_HPP_
#define ENEMYFACTORY_HPP_
#include "Scene.hpp"

namespace ECS {
    class EnemyFactory {
        public:
            EnemyFactory();
            ~EnemyFactory();

            /**
             * @brief Generate enemies
             * 
             * @param scene 
             */
            void generateEnemy(ECS::Scene &scene);
        protected:
        private:
    };
}

#endif /* !ENEMYFACTORY_HPP_ */
