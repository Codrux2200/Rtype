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
            /**
             * @brief Construct a new HitboxComponent object
             * @param callback The callback to call when the entity collides with another entity
             */
            HitboxComponent(hitboxCallback callback);

            HitboxComponent(const HitboxComponent &other);

            /**
             * @brief Construct a new HitboxComponent object
             * @param callback The callback to call when the entity collides with another entity
             * @param std::vector<std::pair<int, int>> The given hitbox of the entity
             */
            explicit HitboxComponent(hitboxCallback callback, const std::vector<std::pair<int, int>> &hitbox);

            /**
             * @brief Sets the hitbox parameters
             * @param std::vector<std::pair<int, int>> The given hitbox vector of int pairs, corresponding to the hitbox corners and coordinates
             */
            void setHitbox(const std::vector<std::pair<int, int>> &hitbox);
            /**
             * @brief Gets the hitbox parameters
             * @return std::vector<std::pair<int, int>> The hitbox vector of int pairs, corresponding to the hitbox corners and coordinates
             */
            [[nodiscard]] const std::vector<std::pair<int, int>> &getHitbox() const;

            /**
             * @brief Clones the hitbox component
             * @return std::shared_ptr<IComponent> The cloned hitbox component pointer
             */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief Calls for the callback of the entity containing the hitbox component
             * @param self
             * @param other
             * @param packetsQueue
             */
            void executeCallback(std::shared_ptr<Entity> self, std::shared_ptr<Entity> other, std::vector<Network::Packet> &packetsQueue) const;

        private:
            /**
             * @brief The hitbox corners and coordinates
             */
            std::vector<std::pair<int, int>> _hitbox;
            /**
             * @brief The callback to call when the entity collides with another entity
             */
            hitboxCallback _callback;
    };

} // namespace ECS

