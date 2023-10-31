/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#include "BossComponent.hpp"

#include <utility>
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

namespace ECS {
    BossComponent::BossComponent(bossShootFunction shootFunction) : _shootFunction(std::move(shootFunction))
    {
    }

    std::shared_ptr<IComponent> BossComponent::clone() const
    {
        return std::make_shared<BossComponent>(_shootFunction);
    }

    void BossComponent::update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt)
    {
        Entity::BossState previousState = _state;

        _timer += dt;
        switch (_state) {
            case Entity::COMING:
                _comingUpdate(entity, dt);
                break;
            case Entity::IDLE:
                _idleUpdate();
                break;
            case Entity::DASH:
                _dashUpdate(entity, dt);
                break;
            case Entity::MOVE:
                _moveUpdate(entity, dt);
                break;
            case Entity::ATTACK_UP:
                _attackUpUpdate(entity);
                break;
            case Entity::ATTACK_DOWN:
                _attackDownUpdate(entity);
                break;
            case Entity::SHOOT:
                _shootUpdate();
                break;
            case Entity::DEAD: break;
        }

        if (previousState != _state) {
            _timer = 0;
            _step = 0;
            // TODO: send state to clients
        }
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

    void BossComponent::_idleUpdate()
    {
        if (_timer >= 3) {
            int random = std::rand() % 5;

            switch (random) {
                case 0:
                    _state = Entity::ATTACK_UP;
                    break;
                case 1:
                    _state = Entity::ATTACK_DOWN;
                    break;
                case 2:
                    _state = Entity::DASH;
                    break;
                case 3:
                    _state = Entity::MOVE;
                    break;
                case 4:
                    _state = Entity::SHOOT;
                    break;
                default:
                    break;
            }
        }
    }

    void BossComponent::_dashUpdate(Entity &entity, float dt)
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

    void BossComponent::_moveUpdate(Entity &entity, float dt)
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

    void BossComponent::_attackUpUpdate(Entity &entity)
    {
        switch (_step) {
            // Wait the animation by preparing the player
            case 0:
                if (_timer >= 3) {
                    _step = 1;
                }
                break;

            // Enable the hitbox of the laser
            case 1: {
                auto hbComp = _getHitboxStartingAt(entity, -500, 0);

                if (hbComp != nullptr)
                    hbComp->isEnabled = true;
                _step = 2;
                _timer = 0;
                break;
            }

            // Wait the end of the shoot
            case 2:
                if (_timer >= 2) {
                    _step = 3;
                }
                break;

            // Disable the hitbox of the laser, and go back to idle
            case 3: {
                auto hbComp = _getHitboxStartingAt(entity, -500, 0);

                if (hbComp != nullptr) {
                    hbComp->isEnabled = false;
                }
                _state = Entity::IDLE;
                break;
            }
        }
    }

    void BossComponent::_attackDownUpdate(Entity &entity)
    {
        switch (_step) {
            // Wait the animation by preparing the player
            case 0:
                if (_timer >= 3) {
                    _step = 1;
                }
                break;

            // Enable the hitbox of the laser
            case 1: {
                auto hbComp = _getHitboxStartingAt(entity, -500, 180);

                if (hbComp != nullptr)
                    hbComp->isEnabled = true;
                _step = 2;
                _timer = 0;
                break;
            }

            // Wait the end of the shoot
            case 2:
                if (_timer >= 2) {
                    _step = 3;
                }
                break;

            // Disable the hitbox of the laser, and go back to idle
            case 3: {
                auto hbComp = _getHitboxStartingAt(entity, -500, 180);

                if (hbComp != nullptr) {
                    hbComp->isEnabled = false;
                }
                _state = Entity::IDLE;
                break;
            }
        }
    }

    void BossComponent::_shootUpdate()
    {
        switch (_step) {
            case 0:
                if (_timer >= 1) {
                    _step = 1;
                }
                break;
            case 1:
                _shootFunction();
                _state = Entity::IDLE;
                break;
        }
    }

    std::shared_ptr<HitboxComponent>
    BossComponent::_getHitboxStartingAt(ECS::Entity &entity, int x, int y)
    {
        for (const auto& hitboxComponent : entity.getComponents<HitboxComponent>()) {
            if (hitboxComponent == nullptr)
                continue;
            auto hitbox = hitboxComponent->getHitbox();

            if (hitbox.empty())
                continue;

            if (hitbox[0].first == x && hitbox[0].second == y)
                return hitboxComponent;
        }
        return nullptr;
    }
} // namespace ECS
