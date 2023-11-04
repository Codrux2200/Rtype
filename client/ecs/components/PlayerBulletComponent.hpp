/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class PlayerBulletComponent : public AGameComponent {
        public:
            PlayerBulletComponent() = default;
            ~PlayerBulletComponent() = default;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;

            int damage = 1;
            bool onDestroy(Entity &entity, Network::data::DeathReason reason, float dt) override;

        private:
            bool Hitinitialize = false;
    };
}
