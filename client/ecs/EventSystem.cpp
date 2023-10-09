/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** EventSystem
*/

#include "EventSystem.hpp"
#include "PositionComponent.hpp"
#include <iostream>

ECS::EventSystem::EventSystem()
    : ASystem(ECS::SystemType::EVENT)
{
}

ECS::EventSystem::~EventSystem()
{
}

static void movePlayer(ECS::Entity *player)
{
    std::vector<int> position;

    ECS::PositionComponent *positionComponent = dynamic_cast<ECS::PositionComponent *>(player->components.at(2));
    position = positionComponent->getValue();

    bool isModified = false;

    // Movement left and up
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    && position.at(0) > 1 && position.at(1) > 1) {
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1) - 1);
        isModified = true;
    }
    // Movement right and up
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    && position.at(0) > 1 && position.at(1) < (800 - 128)) {
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1) + 1);
        isModified = true;
    }
    // Movement left and down
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    && position.at(0) < (600 - 100) && position.at(1) > 1) {
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1) - 1);
        isModified = true;
    }
    // Movement right and down
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    && position.at(0) < (600 - 100) && position.at(1) < (800 - 128)) {
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1) + 1);
        isModified = true;
    }
    // Movement up
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    && position.at(1) > 1) {
        player->components.at(2)->setValue(position.at(0), position.at(1) - 1);
        isModified = true;
    }
    // Movement down
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    && position.at(1) < (600 - 100)) {
        player->components.at(2)->setValue(position.at(0), position.at(1) + 1);
        isModified = true;
    }
    // Movement left
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    && position.at(0) > 1) {
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1));
        isModified = true;
    }
    // Movement right
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    && position.at(0) < (800 - 128)) {
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1));
        isModified = true;
    }
}

void ECS::EventSystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime)
{
    ECS::Scene &actualScene = sceneManager.getScene(SceneType);
    ECS::Entity *player = actualScene.entitiesList.at(1);
    std::vector<int> position;

    // update with a movement event
    movePlayer(player);
}
