/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#include <iostream>
#include <utility>
#include "BossComponent.hpp"
#include "PositionComponent.hpp"
#include "SoundComponent.hpp"
#include "SpriteComponent.hpp"

namespace ECS {

    BossComponent::BossComponent(bossLaserGenerator laserGenerator) : _laserGenerator(std::move(laserGenerator))
    {
        _idleTexture = std::make_shared<sf::Texture>();
        _attackUpTexture = std::make_shared<sf::Texture>();
        _attackDownTexture = std::make_shared<sf::Texture>();

        // load and store textures
        if (!_idleTexture->loadFromFile("assets/boss/boss2.png")) {
            std::cerr << "Error loading boss texture" << std::endl;
            return;
        }

        if (!_attackUpTexture->loadFromFile("assets/boss/boss_eyes_shot.png")) {
            std::cerr << "Error loading boss texture" << std::endl;
            return;
        }

        if (!_attackDownTexture->loadFromFile("assets/boss/boss mouth laser.png")) {
            std::cerr << "Error loading boss texture" << std::endl;
            return;
        }
    }

    BossComponent::BossComponent(const BossComponent &other)
     : AGameComponent(other) {
        _idleTexture = other._idleTexture;
        _attackUpTexture = other._attackUpTexture;
        _attackDownTexture = other._attackDownTexture;
        _state = other._state;
        _timer = other._timer;
        _step = other._step;
        _speed = other._speed;
        _isUp = other._isUp;
        _soundPlayed = other._soundPlayed;
        _laserGenerator = other._laserGenerator;
    }

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
            case Network::data::ATTACK_UP:
                _attackUpUpdate(entity);
                break;
            case Network::data::ATTACK_DOWN:
                _attackDownUpdate(entity);
                break;
            case Network::data::SHOOT:
                _shootUpdate();
                break;
            case Network::data::IDLE:
                _idleUpdate(entity);
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
        return std::make_shared<BossComponent>(*this);
    }

    bool BossComponent::onDestroy(
    Entity &entity, Network::data::DeathReason reason, float dt)
    {
        auto sound = entity.getComponent<SoundComponent>();
        auto sprite = entity.getComponent<SpriteComponent>();
        bool canBeDestroyed = true;

        if (sound) {
            if (!_soundPlayed) {
                sound->play("boss_death");
                _soundPlayed = true;
            }
            if (sound->isPlaying("boss_death"))
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

    void BossComponent::setState(Network::data::BossState state, int isUp)
    {
        _timer = 0;
        _step = 0;
        _state = state;
        _isUp = isUp;
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
                positionComponent->x += dt * _speed / 2;

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
        switch (_step) {
            case 0: {
                _setAttackUpLoadingTexture(entity);
                _step = 1;
            }
            case 1: {
                if (_timer >= 0.9) {
                    auto sound = entity.getComponent<SoundComponent>();
                    auto position = entity.getComponent<PositionComponent>();

                    if (sound)
                        sound->play("boss_eyes_atk");
                    if (position)
                        _laserGenerator("bossEyesLaser", position->x + 70, position->y + 86.5f);
                    _setAttackUpTexture(entity);
                    _step = 2;
                }
                break;
            }
            case 2: {
                if (_timer >= 2) {
                    _setIdleTexture(entity);
                    _state = Network::data::IDLE;
                }
            }
        }
    }

    void BossComponent::_attackDownUpdate(ECS::Entity &entity)
    {
        switch (_step) {
            case 0: {
                _setAttackDownLoadingTexture(entity);
                _step = 1;
            }
            case 1:
                if (_timer >= 0.9) {
                    _setAttackDownTexture(entity);
                    _step = 2;
                }
                break;
            case 2: {
                if (_timer >= 2) {
                    _setIdleTexture(entity);
                    _state = Network::data::IDLE;
                }
            }
        }
    }

    void BossComponent::_shootUpdate()
    {
        //TODO: Animation

    }

    void BossComponent::_idleUpdate(ECS::Entity &entity)
    {
        if (_step == 0) {
            _setIdleTexture(entity);
            _step = 1;
        }
    }

    void BossComponent::_setIdleTexture(Entity &entity)
    {
        auto sprite = entity.getComponent<SpriteComponent>();

        if (sprite == nullptr)
            return;

        sprite->setTexture(_idleTexture);
        sprite->spriteGrid = sf::Vector2i(1, 1);
        sprite->maxIterations = 0;
        sprite->animSpeed = 0;
        sprite->isAnimated = false;
        sprite->setAnimationStep(0);
    }

    void BossComponent::_setAttackUpLoadingTexture(Entity &entity)
    {
        auto sprite = entity.getComponent<SpriteComponent>();

        if (sprite == nullptr)
            return;

        sprite->setTexture(_attackUpTexture);
        sprite->spriteGrid = sf::Vector2i(3, 1);
        sprite->maxIterations = 2;
        sprite->animSpeed = 0.1;
        sprite->isAnimated = true;
        sprite->setAnimationStep(0);
    }

    void BossComponent::_setAttackUpTexture(Entity &entity)
    {
        auto sprite = entity.getComponent<SpriteComponent>();

        if (sprite == nullptr)
            return;

        sprite->setTexture(_attackUpTexture);
        sprite->spriteGrid = sf::Vector2i(3, 1);
        sprite->maxIterations = 0;
        sprite->animSpeed = 0;
        sprite->isAnimated = false;
        sprite->setAnimationStep(2);
    }

    void BossComponent::_setAttackDownLoadingTexture(Entity &entity)
    {
        auto sprite = entity.getComponent<SpriteComponent>();

        if (sprite == nullptr)
            return;

        sprite->setTexture(_attackDownTexture);
        sprite->spriteGrid = sf::Vector2i(5, 1);
        sprite->maxIterations = 2;
        sprite->animSpeed = 0.1;
        sprite->isAnimated = true;
        sprite->setAnimationStep(0);
    }

    void BossComponent::_setAttackDownTexture(Entity &entity)
    {
        auto sprite = entity.getComponent<SpriteComponent>();

        if (sprite == nullptr)
            return;

        sprite->setTexture(_attackDownTexture);
        sprite->spriteGrid = sf::Vector2i(5, 1);
        sprite->maxIterations = 0;
        sprite->animSpeed = 0;
        sprite->isAnimated = false;
        sprite->setAnimationStep(4);
    }
}
