/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** HitboxComponent
*/

#include "HitboxComponent.hpp"

ECS::HitboxComponent::HitboxComponent(int x, int y, int height, int weight, int uid)
{
    _uid = uid;
    _x = x;
    _y = y;
    _height = height;
    _weight = weight;
}

ECS::HitboxComponent::~HitboxComponent()
{
}

void ECS::HitboxComponent::setValue(int x, int y)
{
    _x = x;
    _y = y;
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