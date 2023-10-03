/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"

ECS::PlayerComponent::PlayerComponent(int uid, const std::string& spritePath)
    : AComponent(uid), spritePath("../../assets/Ship6.png")
{
}

ECS::PlayerComponent::~PlayerComponent()
{
}

void ECS::PlayerComponent::setSprite(const std::string& newSpritePath)
{
    spritePath = newSpritePath;
}

std::string ECS::PlayerComponent::getSprite() const
{
    return spritePath;
}