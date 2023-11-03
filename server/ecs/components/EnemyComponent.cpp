/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyComponent
*/

#include <complex>
#include <iostream>
#include "EnemyComponent.hpp"
#include "PositionComponent.hpp"

namespace ECS {
    EnemyComponent::EnemyComponent(EnemyShootFunction shootFunction, ECS::Entity::EntityType type) : _shootFunction(shootFunction), _type(type)
    {
        switch (type) {
            case ECS::Entity::ENEMY_CLASSIC:
                _speed = 100;
                _rate = 3;
                _timer = 0;
                break;
            case ECS::Entity::ENEMY_VELOCE:
                _speed = 200; // Why don't we see it ?
                _rate = 1;
                _timer = 0;
                break;
            default:
                break;
        }
    }

    std::shared_ptr<ECS::IComponent> EnemyComponent::clone() const
    {
        return std::make_shared<EnemyComponent>(_shootFunction, _type);
    }

    void EnemyComponent::update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<ECS::PositionComponent>();

        if (positionComponent == nullptr)
            return;
        _timer += deltaTime;

        switch (_type) {
            case ECS::Entity::ENEMY_CLASSIC:
                positionComponent->x -= _speed * deltaTime;
                break;
            case ECS::Entity::ENEMY_VELOCE:
                positionComponent->y += std::sin(positionComponent->x / 100) * 10;
                break;
            default:
                break;
        }

        if (positionComponent->x < -100) { // TODO: idéalement remplacer le -100 par la taille de l'ennemi
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }

        if (_timer > _rate && _shootFunction != nullptr) {
            _timer = 0;
            _shootFunction(positionComponent->x, positionComponent->y - 10);
            std::cout << "ennemy shoot" << std::endl;
        }
    }
}