/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ShootComponent
*/

#include <iostream>
#include "ShootComponent.hpp"

ECS::ShootComponent::ShootComponent(int shootSpeed, int shootDamage)
{
    _shootSpeed = shootSpeed;
    _shootDamage = shootDamage;
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
