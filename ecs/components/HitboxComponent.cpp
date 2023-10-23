/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HitboxComponent
*/

#include "HitboxComponent.hpp"

ECS::HitboxComponent::HitboxComponent(int x, int y, int height, int weight)
{
    _x = x;
    _y = y;
    _height = height;
    _weight = weight;
}

ECS::HitboxComponent::~HitboxComponent()
{
}

void ECS::HitboxComponent::setValue(std::vector<int> hitbox)
{
    _x = hitbox[0];
    _y = hitbox[1];
    _height = hitbox[2];
    _weight = hitbox[3];
}

std::vector<int> ECS::HitboxComponent::getValue() const
{
    std::vector<int> hitbox = std::vector<int>();
    hitbox.push_back(_x);
    hitbox.push_back(_y);
    hitbox.push_back(_height);
    hitbox.push_back(_weight);
    return hitbox;
}
