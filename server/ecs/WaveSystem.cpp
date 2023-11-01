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
    int EnemyCount = 0;
    std::shared_ptr<ECS::Entity> ennemy = std::make_shared<ECS::EnemyEntity>(0);
    if (ennemy == NULL)
        return;
    for ( ; EnemyCount < 6; EnemyCount++) {
        createEnemy(WaveCount, EnemyCount, 800 + (EnemyCount * 100), 200);
        }
    _waves.push_back(EnemyCount);
    EnemyCount = 0;
    WaveCount++;
    ennemy = std::make_shared<ECS::EnemyEntity>(0);
    if (ennemy == NULL)
        return;
    for (; EnemyCount < 6; EnemyCount++) {
        createEnemy(WaveCount, EnemyCount, 800, 300 + (EnemyCount * 100));
    }
    _waves.push_back(EnemyCount);
    EnemyCount = 0;
    WaveCount++;

    createEnemy(WaveCount, EnemyCount, 800, 300);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 900, 400);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 900, 200);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 1000, 100);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 1000, 500);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 900, 300);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 1000, 300);
    EnemyCount ++;

    createEnemy(WaveCount, EnemyCount, 1000, 300);
    EnemyCount ++;
    _waves.push_back(EnemyCount);
    EnemyCount = 0;
    WaveCount++;
}

void ECS::WaveSystem::createEnemy(int waveCount, int enemyCount, int x, int y) {
    std::shared_ptr<ECS::Entity> enemy = std::make_shared<ECS::EnemyEntity>(0);
    if (enemy == NULL)
        return;
    std::shared_ptr<ECS::PositionComponent> positionComponent =
        enemy->getComponent<ECS::PositionComponent>();
    if (positionComponent == NULL)
        return;
    positionComponent->setValue({x, y});
    _factory.registerEntity(
        enemy, "EnemyWave" + std::to_string(waveCount) + std::to_string(enemyCount));
}

void ECS::WaveSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    // Pick a random wave
    timer += deltaTime;
    if (timer < 5)
        return;
    timer = 0;
    int waveIndex = rand() % _waves.size();
    std::vector<std::shared_ptr<ECS::Entity>> waveEntities = getWave(waveIndex);

    // Spawn the wave entities
    for (auto entity : waveEntities) {
        Network::data::EntitySpawnData data;
        data.id = entity->getId();
        data.type = ECS::Entity::ENEMY_CLASSIC;
        data.x = entity->getComponent<ECS::PositionComponent>()->x;
        data.y = entity->getComponent<ECS::PositionComponent>()->y;
        std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::ENTITY_SPAWN, &data);
        packetQueue.push_back(*packet);
        sceneManager.getCurrentScene()->addEntity(entity);
    }
}

std::vector<std::shared_ptr<ECS::Entity>> ECS::WaveSystem::getWave(int i)
{
    std::vector<std::shared_ptr<ECS::Entity>> result;

    for (int j = 0; j < _waves[i]; j++) {
        result.push_back(_factory.createEntity("EnemyWave" + std::to_string(i) + std::to_string(j), _factory.ids++));
    }
    return result;
}