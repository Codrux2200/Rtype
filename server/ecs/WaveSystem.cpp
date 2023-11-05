/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WaveSystem
*/

#include "WaveSystem.hpp"
#include "EnemyEntity.hpp"
#include <iostream>

ECS::WaveSystem::WaveSystem(EntityFactory &Factory) : _factory(Factory)
{
    int WaveCount = 0;
    int EnemyCount = 0;

    // Wave 0
    std::shared_ptr<ECS::Entity> enemy = _factory.createEntity("entity" + std::to_string(ECS::Entity::ENEMY_CLASSIC), 0);
    if (enemy == nullptr)
        return;
    for ( ; EnemyCount < 8; EnemyCount++) {
        createEnemy(WaveCount, EnemyCount, 800 + (EnemyCount * 50), 200);
        }
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_CLASSIC));

    EnemyCount = 0;
    WaveCount++;

    // Wave 1
    enemy = _factory.createEntity("entity" + std::to_string(ECS::Entity::ENEMY_CLASSIC), 0);
    if (enemy == nullptr)
        return;
    for (; EnemyCount < 8; EnemyCount++) {
        createEnemy(WaveCount, EnemyCount, 800, 300 + (EnemyCount * 50 + std::rand() % 10));
    }
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_CLASSIC));

    EnemyCount = 0;
    WaveCount++;

    // Wave 2
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
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_CLASSIC));

    EnemyCount = 0;
    WaveCount++;

    // Wave 3
    createEnemy(WaveCount, EnemyCount, 800, 10);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800, 50);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 850, 150);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 900, 250);
    EnemyCount ++;
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_CLASSIC));
    EnemyCount = 0;
    WaveCount++;

    // Wave 4
    createEnemy(WaveCount, EnemyCount, 800, 580);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800, 550);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 850, 450);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 900, 350);
    EnemyCount ++;
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_CLASSIC));
    EnemyCount = 0;
    WaveCount++;

    // Wave 5
    createEnemy(WaveCount, EnemyCount, 800, 200, ECS::Entity::ENEMY_VELOCE);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 850, 300, ECS::Entity::ENEMY_VELOCE);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800, 400, ECS::Entity::ENEMY_VELOCE);
    EnemyCount ++;
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_VELOCE));
    EnemyCount = 0;
    WaveCount++;

    // Wave 6
    createEnemy(WaveCount, EnemyCount, 800, 300);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 850, 350);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 850, 250);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 900, 400);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 900, 200);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800, 400);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800, 200);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 1000, 550);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 1000, 150);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 1100, 500);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 1100, 50);
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_VELOCE));
    EnemyCount = 0;
    WaveCount++;

    // Wave 7
    createEnemy(WaveCount, EnemyCount, 800, 20);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800, 50);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 900, 20);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 900, 50);
    EnemyCount ++;
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_CLASSIC));
    EnemyCount = 0;
    WaveCount++;

    // Wave 8
    createEnemy(WaveCount, EnemyCount, 800, 200, ECS::Entity::ENEMY_VELOCE);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800 + (EnemyCount * 50), 300, ECS::Entity::ENEMY_VELOCE);
    EnemyCount ++;
    createEnemy(WaveCount, EnemyCount, 800 + (EnemyCount * 50), 200, ECS::Entity::ENEMY_VELOCE);
    EnemyCount ++;
    _waves.push_back(std::tuple<int, ECS::Entity::EntityType>(EnemyCount, ECS::Entity::ENEMY_VELOCE));
    EnemyCount = 0;
    WaveCount++;

}

void ECS::WaveSystem::createEnemy(int waveCount, int enemyCount, int x, int y, ECS::Entity::EntityType type)
{
    std::shared_ptr<ECS::Entity> enemy = _factory.createEntity("entity" + std::to_string(type), 0);

    if (enemy == nullptr)
        return;
    std::shared_ptr<ECS::PositionComponent> positionComponent =
        enemy->getComponent<ECS::PositionComponent>();
    if (positionComponent == nullptr)
        return;
    positionComponent->setValue({x, y});
    _factory.registerEntity(
        enemy, "EnemyWave" + std::to_string(waveCount) + std::to_string(enemyCount));
}

void ECS::WaveSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
{
    if (sceneManager.getSceneType() != ECS::SceneType::GAME)
        return;
    // Pick a random wave

    timer += deltaTime;
    if (timer < 3)
        return;
    timer = 0;
    int waveIndex = std::rand() % _waves.size();
    std::vector<std::shared_ptr<ECS::Entity>> waveEntities = getWave(waveIndex);
    ECS::Entity::EntityType type = std::get<1>(_waves[waveIndex]);

    auto scene = sceneManager.getCurrentScene();

    // Spawn the wave entities
    for (auto entity : waveEntities) {
        Network::data::EntitySpawnData data{};
        data.id = entity->getId();
        data.type = type;
        data.x = entity->getComponent<ECS::PositionComponent>()->x;
        data.y = entity->getComponent<ECS::PositionComponent>()->y;
        std::unique_ptr<Network::Packet> packet = Network::PacketManager::createPacket(Network::PacketType::ENTITY_SPAWN, &data);
        packetQueue.push_back(*packet);
        scene->addEntity(entity);
    }
}

std::vector<std::shared_ptr<ECS::Entity>> ECS::WaveSystem::getWave(int i)
{
    std::vector<std::shared_ptr<ECS::Entity>> result;

    if (i >= _waves.size()) {
        std::cerr << "Error: wave index is invalid" << std::endl;
        return result;
    }

    for (int j = 0; j < std::get<0>(_waves[i]); j++) {
        result.push_back(_factory.createEntity("EnemyWave" + std::to_string(i) + std::to_string(j), _factory.ids++));
    }
    return result;
}
