/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** VelocityComponent
*/

#include <iostream>
#include "VelocityComponent.hpp"

namespace ECS {

        VelocityComponent::VelocityComponent(float vx, float vy) : vx(vx), vy(vy)
        {
        }

        std::shared_ptr<IComponent> VelocityComponent::clone() const
        {
            return std::make_shared<VelocityComponent>(vx, vy);
        }
}