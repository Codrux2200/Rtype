//
// Created by raph on 26/10/23.
//

#include "PlayerComponent.hpp"

namespace ECS {
    std::shared_ptr<IComponent> PlayerComponent::clone() const
    {
        return std::make_shared<PlayerComponent>();
    }
} // namespace ECS