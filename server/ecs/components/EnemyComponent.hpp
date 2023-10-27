/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class EnemyComponent : public ECS::AGameComponent {
        public:
            EnemyComponent();
            ~EnemyComponent() = default;

            [[nodiscard]] std::shared_ptr<ECS::IComponent>
            clone() const override;

            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;
        private:
            float _speed = 20;
    };
}