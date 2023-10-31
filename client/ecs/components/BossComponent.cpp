/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#include "BossComponent.hpp"
#include "PositionComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    void BossComponent::update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
    {
        Entity::BossState previousState = _state;

        _timer += dt;
        switch (_state) {
            case Entity::COMING:
                _comingUpdate(entity, dt);
                break;
            case Entity::DASH: _dashUpdate(entity, dt);
                break;
            case Entity::MOVE:
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

    void BossComponent::setState(ECS::Entity::BossState state)
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
            _state = Entity::IDLE;
        }
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
                    _state = Entity::IDLE;
                }
                break;
        }
    }

    void BossComponent::_moveUpdate(ECS::Entity &entity, float dt)
    {
        auto positionComponent = entity.getComponent<PositionComponent>();

        if (positionComponent == nullptr)
            return;

        positionComponent->y += dt * _speed * _isUp;

        if (positionComponent->y <= ((_isUp < 0.0) ? 0.0 : 240)) {
            positionComponent->y = static_cast<float>((_isUp < 0) ? 0 : 240);
            _state = Entity::IDLE;
            _isUp = -_isUp;
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
