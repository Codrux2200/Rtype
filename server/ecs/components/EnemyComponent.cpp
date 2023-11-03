/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include <iostream>
#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"

namespace ECS {
    EnemyComponent::EnemyComponent(EnemyShootFunction shootFunction) : _shootFunction(shootFunction)
    {}

    std::shared_ptr<ECS::IComponent> EnemyComponent::clone() const
    {
        return std::make_shared<EnemyComponent>(_shootFunction);
    }

    void EnemyComponent::update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<ECS::PositionComponent>();

        if (positionComponent == nullptr)
            return;
        timer += deltaTime;
        positionComponent->x -= _speed * deltaTime;
        if (positionComponent->x < 0 - 100) {
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }
        if (timer > rate && _shootFunction != nullptr) {
            timer = 0;
            _shootFunction(positionComponent->x, positionComponent->y - 10);
            std::cout << "ennemy shoot" << std::endl;
        }
    }
}