/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ShootComponent
*/

#include "ShootComponent.hpp"

ECS::ShootComponent::ShootComponent(int shootSpeed, int shootDamage)
{
    _shootSpeed = shootSpeed;
    _shootDamage = shootDamage;
}

ECS::ShootComponent::~ShootComponent()
{
}

void ECS::ShootComponent::setValue(int shootSpeed, int shootDamage)
{
    _shootSpeed = shootSpeed;
    _shootDamage = shootDamage;
}

std::vector<int> ECS::ShootComponent::getValue() const
{
    std::vector<int> shoot = std::vector<int>();
    shoot.push_back(_shootSpeed);
    shoot.push_back(_shootDamage);
    return shoot;
}
