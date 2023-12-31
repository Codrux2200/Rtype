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
#include "SceneManager.hpp"
#include "ISystem.hpp"
#include <vector>

namespace ECS {
    class WaveSystem : public ISystem {
        public:
            WaveSystem(EntityFactory &Factory) ;

            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;
            std::vector<std::shared_ptr<ECS::Entity>> getWave(int i);
            void createEnemy(int WaveCount, int EnemyCount, int x, int y, ECS::Entity::EntityType type = ECS::Entity::ENEMY_CLASSIC);

        protected:
        private:
            EntityFactory &_factory;
            std::vector<std::tuple<int, ECS::Entity::EntityType>> _waves;
            float _timer = 0;
            int _masterTimer = 0;
            bool _isBossSpawned = false;
    };
}


#endif /* !WAVESYSTEM_HPP_ */
