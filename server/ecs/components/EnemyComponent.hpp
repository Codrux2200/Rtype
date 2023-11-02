/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/

#pragma once

#include <functional>
#include "AGameComponent.hpp"

namespace ECS {
    using EnemyShootFunction = std::function<void()>;
    class EnemyComponent : public ECS::AGameComponent {
        public:
            explicit EnemyComponent(EnemyShootFunction shootFunction);
            ~EnemyComponent() = default;

            [[nodiscard]] std::shared_ptr<ECS::IComponent>
            clone() const override;

            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;
        private:
            float _speed = 100;
            float timer = 0;
            float rate = 1;
            EnemyShootFunction _shootFunction;
    };
}