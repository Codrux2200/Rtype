/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyBulletComponent
*/

#include "EnemyBulletComponent.hpp"

namespace ECS {
    EnemyBulletComponent::EnemyBulletComponent(
        int x_bullet_size, int y_bullet_size, EnemyBulletComponent::shoot_type type
    ) : _x_bullet_size(x_bullet_size), _type(type) {};

    std::shared_ptr<IComponent> EnemyBulletComponent::clone() const
    {
        return std::make_shared<EnemyBulletComponent>();
    }

    void EnemyBulletComponent::update(
    std::vector<Network::Packet> &packets, Entity &entity, float deltaTime)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();
        auto velocityComponent = entity.getComponent<VelocityComponent>();

        if (positionComponent == nullptr)
            return;

        switch (this->_type) {
            case CLASSIC:
                move_velocitically(positionComponent, deltaTime, velocityComponent);
                break;
            case TARGETED: move_to_target(positionComponent, deltaTime, velocityComponent);
                break;
            default:
                break;
        }
        if (positionComponent->x < 0 - _x_bullet_size ||
            positionComponent->x > 1920 + _x_bullet_size ||
            positionComponent->y < 0 - _y_bullet_size ||
            positionComponent->y > 1080 + _y_bullet_size) {
            entity.deathReason = Network::data::OUT_OF_BOUNDS;
        }
    }

    void EnemyBulletComponent::move_velocitically(const std::shared_ptr<PositionComponent>& positionComponent, float deltaTime, const std::shared_ptr<VelocityComponent>& velocityComponent)
    {
        positionComponent->x -= velocityComponent->getValue()[0] * deltaTime;
        positionComponent->y -= velocityComponent->getValue()[1] * deltaTime;
    }

    void EnemyBulletComponent::move_to_target(const std::shared_ptr<PositionComponent>& positionComponent, float deltaTime, const std::shared_ptr<VelocityComponent>& velocityComponent)
    {
        if (_target.empty())
            return;
        if (positionComponent->x > _target[0])
            positionComponent->x -= velocityComponent->getValue()[0] * deltaTime;
        else if (positionComponent->x < _target[0]) {
            _type = CLASSIC;
            return;
        }
        if (positionComponent->y > _target[1])
            positionComponent->y -= velocityComponent->getValue()[1] * deltaTime;
        else if (positionComponent->y < _target[1])
            positionComponent->y += velocityComponent->getValue()[1] * deltaTime;
    }
}