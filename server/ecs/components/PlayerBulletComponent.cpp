/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#include "PlayerBulletComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerBulletComponent::clone() const
    {
        return std::make_shared<PlayerBulletComponent>();
    }
}