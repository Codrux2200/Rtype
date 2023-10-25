/*
** EPITECH PROJECT, 2023
** RType
** File description:
** HitboxComponent
*/

#include "HitboxComponent.hpp"

#include <utility>

namespace ECS {
    HitboxComponent::HitboxComponent(ECS::hitboxCallback callback) : _callback(std::move(callback))
    {}

    HitboxComponent::HitboxComponent(hitboxCallback callback, const std::vector<std::pair<float, float>> &hitbox) : _hitbox(hitbox), _callback(std::move(callback))
    {
    }

    void HitboxComponent::setHitbox(const std::vector<std::pair<float, float>> &hitbox)
    {
        _hitbox = hitbox;
    }

    const std::vector<std::pair<float, float>> &HitboxComponent::getHitbox() const
    {
        return _hitbox;
    }

    std::shared_ptr<IComponent> HitboxComponent::clone() const
    {
        return std::make_shared<HitboxComponent>(_callback, _hitbox);
    }

    void HitboxComponent::executeCallback(std::shared_ptr<Entity> entity) const
    {
        _callback(entity);
    }
} // namespace ECS
