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

    std::shared_ptr<ECS::PositionComponent> positionComponent3 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent3 == NULL)
            return;
        positionComponent3->setValue({800, 300});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent4 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent4 == NULL)
            return;
        positionComponent4->setValue({900, 400});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent5 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent5 == NULL)
            return;
        positionComponent5->setValue({900, 200});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent6 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent6 == NULL)
            return;
        positionComponent6->setValue({1000, 100});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent7 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent7 == NULL)
            return;
        positionComponent7->setValue({1000, 500});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent8 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent8 == NULL)
            return;
        positionComponent8->setValue({900, 300});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent9 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent9 == NULL)
            return;
        positionComponent9->setValue({1000, 300});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;

    std::shared_ptr<ECS::PositionComponent> positionComponent10 =
        ennemy->getComponent<ECS::PositionComponent>();
        if (positionComponent10 == NULL)
            return;
        positionComponent10->setValue({1100, 300});
        _factory.registerEntity(
        ennemy, "EnemyWave" + std::to_string(WaveCount) + std::to_string(EnemyCount));
    EnemyCount ++;
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