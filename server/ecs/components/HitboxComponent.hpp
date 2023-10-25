/*
** EPITECH PROJECT, 2023
** RType
** File description:
** HitboxComponent
*/

#pragma once

#include <functional>
#include "AComponent.hpp"
#include "Entity.hpp"

namespace ECS {

    using hitboxCallback = std::function<void(std::shared_ptr<Entity>)>;

    class HitboxComponent : public AComponent {
        public:
            HitboxComponent(hitboxCallback callback);
            explicit HitboxComponent(hitboxCallback callback, const std::vector<std::pair<float, float>> &hitbox);

            void setHitbox(const std::vector<std::pair<float, float>> &hitbox);
            [[nodiscard]] const std::vector<std::pair<float, float>> &getHitbox() const;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void executeCallback(std::shared_ptr<Entity> entity) const;

        private:
            std::vector<std::pair<float, float>> _hitbox;
            hitboxCallback _callback;
    };

} // namespace ECS

