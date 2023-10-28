/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerComponent
*/


#include "PlayerComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerComponent::clone() const
    {
        return std::make_shared<PlayerComponent>();
    }
} // namespace ECS