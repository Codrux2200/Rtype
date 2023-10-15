/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ShootComponent
*/

#include "ShootComponent.hpp"

ECS::ShootComponent::ShootComponent(int uid, int shootSpeed, int shootDamage)
    : AComponent(uid)
{
    _shootSpeed = shootSpeed;
    _shootDamage = shootDamage;
}

ECS::ShootComponent::~ShootComponent()
{
}

void ECS::ShootComponent::setShootSpeed(int shootSpeed)
{
    _shootSpeed = shootSpeed;
}

void ECS::ShootComponent::setShootDamage(int shootDamage)
{
    _shootDamage = shootDamage;
}

int ECS::ShootComponent::getShootSpeed() const
{
    return _shootSpeed;
}

int ECS::ShootComponent::getShootDamage() const
{
    return _shootDamage;
}