/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyFactory
*/

#include <experimental/random>
#include "EnemyFactory.hpp"
#include "EnemyComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
#include "HitboxComponent.hpp"
#include <iostream>

ECS::EnemyFactory::EnemyFactory()
{
}

ECS::EnemyFactory::~EnemyFactory()
{
}

void ECS::EnemyFactory::generateEnemy(ECS::Scene &scene)
{
    std::vector<ECS::Tag> tags;
    int nbMaxEnemies = std::experimental::randint(1, 4);
    int randomY = 0;

    tags.push_back(ECS::Tag::DESTROYABLE);
    tags.push_back(ECS::Tag::MOVABLE);
    // create enemy entities and components with nbMaxEnemies as max only if there is no enemy in the scene
    if (scene.entitiesList.size() < 2) {
        for (int i = 0; i < nbMaxEnemies; i++) {
            randomY = std::experimental::randint(0, 472);
            scene.entitiesList.emplace(i + 2, new ECS::Entity(i, tags));
            // have to change the sprite type
            scene.entitiesList.at(i + 2)->components.push_back(new ECS::EnemyComponent((i + 2) * 10, "assets/Ship6.png"));
            scene.entitiesList.at(i + 2)->components.push_back(new ECS::HealthComponent((i + 2) * 10 + 1));
            scene.entitiesList.at(i + 2)->components.push_back(new ECS::PositionComponent(672, randomY, (i + 2) * 10 + 2));
            scene.entitiesList.at(i + 2)->components.push_back(new ECS::HitboxComponent(672, randomY, 128, 128, (i + 2) * 10 + 3));
        }
    }
}