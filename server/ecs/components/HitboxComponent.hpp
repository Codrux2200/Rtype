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
#include "Packet.hpp"

namespace ECS {

    using hitboxCallback = std::function<void(std::shared_ptr<Entity>, std::shared_ptr<Entity>, std::vector<Network::Packet> &)>;

    class HitboxComponent : public AComponent {
        public:
            HitboxComponent(hitboxCallback callback);
            explicit HitboxComponent(hitboxCallback callback, const std::vector<std::pair<int, int>> &hitbox);

            void setHitbox(const std::vector<std::pair<int, int>> &hitbox);
            [[nodiscard]] const std::vector<std::pair<int, int>> &getHitbox() const;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void executeCallback(std::shared_ptr<Entity> self, std::shared_ptr<Entity> other, std::vector<Network::Packet> &packetsQueue) const;

        private:
            std::vector<std::pair<int, int>> _hitbox;
            hitboxCallback _callback;
    };

} // namespace ECS

