/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WaveSystem
*/

#ifndef WAVESYSTEM_HPP_
#define WAVESYSTEM_HPP_

#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"
#include "EntityFactory.hpp"
#include "ISystem.hpp"
#include <vector>

namespace ECS {
    class WaveSystem {
        public:
            WaveSystem(const EntityFactory &Factory) ;

            void update(std::vector<std::shared_ptr<ECS::Entity>> &entitiesList, float deltaTime);
            std::vector<std::shared_ptr<ECS::Entity>> getWave(int i);

        protected:
        private:
            EntityFactory _factory;
            std::vector<int> _waves;
    };
}


#endif /* !WAVESYSTEM_HPP_ */