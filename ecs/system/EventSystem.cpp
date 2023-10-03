/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** EventSystem
*/

#include "EventSystem.hpp"
#include "PositionComponent.hpp"

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
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    && position.at(1) > 0)
        player->components.at(2)->setValue(position.at(0), position.at(1) - 1);
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    && position.at(1) < 720)
        player->components.at(2)->setValue(position.at(0), position.at(1) + 1);
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    && position.at(0) > 0)
        player->components.at(2)->setValue(position.at(0) - 1, position.at(1));
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    && position.at(0) < 1280)
        player->components.at(2)->setValue(position.at(0) + 1, position.at(1));
}

void ECS::EventSystem::update(SceneManager &sceneManager, SceneType SceneType, int deltaTime)
{
    ECS::Scene &actualScene = sceneManager.getScene(SceneType);
    ECS::Entity *player = actualScene.entitiesList.at(0);
    std::vector<int> position;
    // update with a movement event
    movePlayer(player);    
}
