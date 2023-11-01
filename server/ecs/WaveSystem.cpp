/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WaveSystem
*/

#include "WaveSystem.hpp"
#include "EnemyEntity.hpp"
#include <iostream>


ECS::WaveSystem::WaveSystem(const EntityFactory &Factory) : _factory(Factory)
{
    int WaveCount = 0;
    int EnnemyCount = 0;
    std::shared_ptr<ECS::Entity> ennemy = std::make_shared<ECS::EnemyEntity>(0);
    if (ennemy == NULL)
        return;
    for (int i = 0; i < 6; i++) {
        std::shared_ptr<ECS::PositionComponent> positionComponent =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent == NULL)
            return;
        positionComponent->setValue({100, 100 + (i * 100)});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount + EnnemyCount++));

        _waves.push_back(EnnemyCount);
        EnnemyCount = 0;
        std::cout << "At creation : x: " << ennemy->getComponent<ECS::PositionComponent>()->x << "; y: " << ennemy->getComponent<ECS::PositionComponent>()->y << std::endl;
        }

    ennemy = std::make_shared<ECS::EnemyEntity>(0);
    if (ennemy == NULL)
        return;
    for (int i = 0; i < 6; i++) {
        std::shared_ptr<ECS::PositionComponent> positionComponent2 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent2 == NULL)
            return;
        positionComponent2->setValue({100 + (i * 100), 100});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount + EnnemyCount++));
        EnnemyCount = 1;
    }
}

void ECS::WaveSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    // Pick a random wave
    int waveIndex = rand() % _waves.size();
    std::vector<std::shared_ptr<ECS::Entity>> waveEntities = getWave(waveIndex);

    // Spawn the wave entities
    for (auto entity : waveEntities) {
        getWave(waveIndex);
    }
}

std::vector<std::shared_ptr<ECS::Entity>> ECS::WaveSystem::getWave(int i)
{
    std::vector<std::shared_ptr<ECS::Entity>> result;

    for (int j = 0; j < _waves[i]; j++) {
        result.push_back(_factory.createEntity(
        "EnemyWave" + std::to_string(i + j), _factory.ids++));
    }
    return result;
}