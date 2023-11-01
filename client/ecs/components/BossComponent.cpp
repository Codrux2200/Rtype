/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#include <iostream>
#include "BossComponent.hpp"
#include "PositionComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    void BossComponent::update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
    {
        Network::data::BossState previousState = _state;

        _timer += dt;
        switch (_state) {
            case Network::data::COMING:
                _comingUpdate(entity, dt);
                break;
            case Network::data::DASH: _dashUpdate(entity, dt);
                break;
            case Network::data::MOVE:
                _moveUpdate(entity, dt);
                break;
            default:
                break;
        }

        if (previousState != _state) {
            _timer = 0;
            _step = 0;
        }
    }

    std::shared_ptr<IComponent> BossComponent::clone() const
    {
        return std::make_shared<BossComponent>();
    }

    bool BossComponent::onDestroy(
    Entity &entity, Network::data::DeathReason reason, float dt)
    {
        auto sound = entity.getComponent<SoundComponent>();
        auto sprite = entity.getComponent<SpriteComponent>();
        bool canBeDestroyed = true;

        if (sound) {
            if (!_soundPlayed) {
                sound->play();
                _soundPlayed = true;
            }
            if (sound->isPlaying())
                canBeDestroyed = false;
        }

//        if (sprite) {
//            if (!_spriteChanged) {
//                sprite->sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
//                _spriteChanged = true;
//            }
//            if (sprite->sprite.getTextureRect().width != 0)
//                canBeDestroyed = false;
//        }

        return canBeDestroyed;
    }

    void BossComponent::setState(Network::data::BossState state)
    {
        _timer = 0;
        _step = 0;
        _state = state;
    }

    void BossComponent::_comingUpdate(ECS::Entity &entity, float dt)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            return;

        positionComponent->x -= dt * (_speed / 2);
        if (positionComponent->x <= 500) {
            positionComponent->x = 500;
            _state = Network::data::IDLE;
        }
        std::cout << "Coming" << std::endl;
    }

    void BossComponent::_dashUpdate(ECS::Entity &entity, float dt)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            return;

        switch (_step) {
            case 0:
                if (_timer >= 2) {
                    _step = 1;
                }
            case 1:
                positionComponent->x -= dt * _speed;

                if (positionComponent->x < 267) {
                    _step = 2;
                    positionComponent->x = 267;
                }
                break;
            case 2:
                positionComponent->x += dt * _speed;

                if (positionComponent->x > 500) {
                    positionComponent->x = 500;
                    _state = Network::data::IDLE;
                }
                break;
        }
    }

    void BossComponent::_moveUpdate(ECS::Entity &entity, float dt)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();

        if (positionComponent == nullptr) {
            std::cout << "No position component" << std::endl;
            return;
        }

        positionComponent->y += dt * _speed * _isUp;

        if (_isUp == 1 && positionComponent->y >= 240) {
            _state = Network::data::IDLE;
            _isUp = -1;
        } else if (_isUp == -1 && positionComponent->y <= 0) {
            _state = Network::data::IDLE;
            _isUp = 1;
        }
    }

    void BossComponent::_attackUpUpdate(ECS::Entity &entity)
    {
        // TODO: Animation
    }

    void BossComponent::_attackDownUpdate(ECS::Entity &entity)
    {
        // TODO: Animation
    }

    void BossComponent::_shootUpdate()
    {
        //TODO: Animation
    }
}
