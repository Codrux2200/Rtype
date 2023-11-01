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
            WaveSystem(const EntityFactory &Factory) ;

            void update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue) override;
            std::vector<std::shared_ptr<ECS::Entity>> getWave(int i);

        protected:
        private:
            EntityFactory _factory;
            std::vector<int> _waves;
    };
}


#endif /* !WAVESYSTEM_HPP_ */
