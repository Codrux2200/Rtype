/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** EventSystem
*/

#include "EventSystem.hpp"

ECS::EventSystem::EventSystem()
{
    typeSystem = ECS::SystemType::EVENT;
}

ECS::EventSystem::~EventSystem()
{
}

void ECS::EventSystem::_moveLeftUp(ECS::Entity *player, std::vector<int> position)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    && position.at(0) > 1 && position.at(1) > 1)
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1) - 1);

}

void ECS::EventSystem::_moveRightUp(ECS::Entity *player, std::vector<int> position)
{
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    && position.at(0) > 1 && position.at(1) < (800 - 128))
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1) + 1);
}

void ECS::EventSystem::_moveLeftDown(ECS::Entity *player, std::vector<int> position)
{
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    && position.at(0) < (600 - 100) && position.at(1) > 1)
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1) - 1);
}

void ECS::EventSystem::_moveRightDown(ECS::Entity *player, std::vector<int> position)
{
    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    && position.at(0) < (600 - 100) && position.at(1) < (800 - 128))
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1) + 1);
}

void ECS::EventSystem::_moveUp(ECS::Entity *player, std::vector<int> position)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    && position.at(1) > 1)
        player->components.at(2)->setValue(position.at(0), position.at(1) - 1);
}

void ECS::EventSystem::_moveDown(ECS::Entity *player, std::vector<int> position)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    && position.at(1) < (600 - 100))
        player->components.at(2)->setValue(position.at(0), position.at(1) + 1);
}

void ECS::EventSystem::_moveLeft(ECS::Entity *player, std::vector<int> position)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    && position.at(0) > 1)
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1));
}

void ECS::EventSystem::_moveRight(ECS::Entity *player, std::vector<int> position)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    && position.at(0) < (800 - 128))
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1));
}

void ECS::EventSystem::_movePlayer(ECS::Entity *player)
{
    std::vector<int> position;

    ECS::PositionComponent *positionComponent = dynamic_cast<ECS::PositionComponent *>(player->components.at(2));
    position = positionComponent->getValue();
    // Movement left and up
    _moveLeftUp(player, position);
    // Movement right and up
    _moveRightUp(player, position);
    // Movement left and down
    _moveLeftDown(player, position);
    // Movement right and down
    _moveRightDown(player, position);
    // Movement up
    _moveUp(player, position);
    // Movement down
    _moveDown(player, position);
    // Movement left
    _moveLeft(player, position);
    // Movement right
    _moveRight(player, position);
}

void ECS::EventSystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime)
{
    ECS::Scene &actualScene = sceneManager.getScene(SceneType);
    ECS::Entity *player = actualScene.entitiesList.at(1);
    std::vector<int> position;

    // update with a movement event
    _movePlayer(player);
}
