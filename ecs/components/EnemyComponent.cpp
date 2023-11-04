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
                _xspeed = 100;
                _rate = 2 + _random;
                _timer = 0;
                break;
            case ECS::Entity::ENEMY_VELOCE:
                _xspeed = 500;
                _yspeed = 100;
                _rate = 0.5;
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
            case ECS::Entity::ENEMY_CLASSIC: positionComponent->x -= _xspeed * deltaTime; break;
            case ECS::Entity::ENEMY_VELOCE:
                if (positionComponent->y > 400 && _yspeed > 0) {
                    std::cout << "Switching VELOCE Y" << std::endl;
                    _yspeed = -100;
                } else if (positionComponent->y < 150 && _yspeed < 0)
                    _yspeed = 100;
                positionComponent->y += _yspeed * deltaTime;
                positionComponent->x -= _xspeed * deltaTime;
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