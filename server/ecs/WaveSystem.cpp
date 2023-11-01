/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WaveSystem
*/

#include "WaveSystem.hpp"
#include "EnemyEntity.hpp"


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

void ECS::WaveSystem::update(
std::vector<std::shared_ptr<ECS::Entity>> &entitiesList, float deltaTime)
{
    for (int i = 0; i < _waves.size(); i++) {
        for (int j = 0; j < _waves[i]; j++) {
            std::shared_ptr<ECS::Entity> enemy = _factory.createEntity(
            "EnemyWave" + std::to_string(i + j), _factory.ids++);
            if (enemy != nullptr) {
                entitiesList.push_back(enemy);
                std::shared_ptr<ECS::PositionComponent> positionComponent =
                enemy->getComponent<ECS::PositionComponent>();
                if (positionComponent != nullptr) {
                    if (rand() % 2 == 0) {
                        std::cout << "At creation : x: " << enemy->getComponent<PositionComponent>()->x << "; y: " << enemy->getComponent<PositionComponent>()->y << std::endl;
                    }
                }
            }
        }
    }
}

std::vector<ECS::Entity> ECS::WaveSystem::getWave(int i)
{
    std::vector<std::shared_ptr<ECS::Entity>> result;

    for (int j = 0; j < _waves[i]; j++) {
        result.push_back(_factory.createEntity(
        "EnemyWave" + std::to_string(i + j), _factory.ids++));
    }
}