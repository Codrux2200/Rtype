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
        std::shared_ptr<ECS::PositionComponent> positionComponent =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent == NULL)
            return;
        positionComponent->setValue({800, 200 + (EnemyCount * 100)});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));

        std::cout << "At creation : x: " << ennemy->getComponent<ECS::PositionComponent>()->x << "; y: " << ennemy->getComponent<ECS::PositionComponent>()->y << std::endl;
        }
    _waves.push_back(EnemyCount);
    EnemyCount = 0;
    WaveCount++;
    ennemy = std::make_shared<ECS::EnemyEntity>(0);
    if (ennemy == NULL)
        return;
    for (; EnemyCount < 6; EnemyCount++) {
        std::shared_ptr<ECS::PositionComponent> positionComponent2 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent2 == NULL)
            return;
        positionComponent2->setValue({800 + (EnemyCount * 100), 200});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    }
    _waves.push_back(EnemyCount);
    EnemyCount = 0;
    WaveCount++;
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