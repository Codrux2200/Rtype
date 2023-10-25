/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ShootComponent
*/

#include "ShootComponent.hpp"


ECS::ShootComponent::ShootComponent(int shootSpeed, int shootDamage, ShootType type)
{
    _shootSpeed = shootSpeed;
    _shootDamage = shootDamage;

    std::shared_ptr<ECS::Entity> shoot = std::make_shared<ECS::Entity>(100);
    shoot->addComponent(std::make_shared<ECS::PositionComponent>(0, 0));
//    shoot->addComponent(std::make_shared<ECS::ScaleComponent>(0.5f, 0.5f)); TO ADJUST

    sf::Texture shootTexture;
    if (!shootTexture.loadFromFile("assets/shoot.png")) {
        std::cerr << "Error loading shoot texture" << std::endl;
        return;
    }

    sf::Rect<int> shootRect;
    // TODO: Rect is ok for NORMAL only, need to be adjusted for other types.
    shootRect.left = type == NORMAL ? 0 : type == BIG ? 40 : type == REVERSE ? 80 : 120;
    shootRect.top = type == NORMAL ? 0 : type == BIG ? 0 : type == REVERSE ? 0 : 0;
    shootRect.width = type == NORMAL ? 40 : type == BIG ? 40 : type == REVERSE ? 40 : 40;
    shootRect.height = type == NORMAL ? 40 : type == BIG ? 40 : type == REVERSE ? 40 : 40;
    shoot->addComponent(std::make_shared<ECS::SpriteComponent>(shootTexture, shootRect));
    shoot->getComponent<ECS::SpriteComponent>()->setMaxIteration(
    sf::Vector2i(
        type == NORMAL ? 3 : type == BIG ? 4 : type == REVERSE ? 0 : 0,
        type == NORMAL ? 0 : type == BIG ? 0 : type == REVERSE ? 0 : 0
        )
    );
    _factory.registerEntity(shoot, "shoot");
}

ECS::ShootComponent::~ShootComponent()
{
}

void ECS::ShootComponent::setValue(std::vector<int> values)
{
    if (values.size() != 2) {
        std::cerr << "Error: setValue in ShootComponent" << std::endl;
        return;
    }
    _shootSpeed = values[0];
    _shootDamage = values[1];
}

std::vector<int> ECS::ShootComponent::getValue() const
{
    std::vector<int> shoot = std::vector<int>();
    shoot.push_back(_shootSpeed);
    shoot.push_back(_shootDamage);
    return shoot;
}

void ECS::ShootComponent::moveShots()
{
    constexpr int SCREEN_WIDTH = 1920;

    auto moveAndCheckBounds = [this](const std::shared_ptr<ECS::Entity>& shot) {
        auto positionComponent = shot->getComponent<ECS::PositionComponent>();
        std::vector<int> pos = positionComponent->getValue();

        positionComponent->move(pos.front() + _shootSpeed, pos.back());

        auto hitbox = shot->getComponent<ECS::HitboxComponent>();
        std::vector<int> newpos = positionComponent->getValue();
        hitbox->setValue(newpos);

        return newpos.front() > SCREEN_WIDTH;
    };

    _shots.erase(std::remove_if(_shots.begin(), _shots.end(), moveAndCheckBounds), _shots.end());
}


void ECS::ShootComponent::newShot(std::vector<int> pos)
{
    auto shot = _factory.createEntity("shoot", std::time(nullptr));
    auto positionComponent = *shot->getComponent<ECS::PositionComponent>();
    positionComponent.setValue(pos);
    _shots.push_back(shot);
}
