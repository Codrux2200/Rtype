/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** EnemyBulletComponent
*/

#pragma once

#include <utility>

#include "AGameComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

namespace ECS {
    class EnemyBulletComponent : public AGameComponent {
        public:
            enum shoot_type {
                CLASSIC,
                TARGETED,
                UNKNOWN
            };

            explicit EnemyBulletComponent(int x_bullet_size = 10, int y_bullet_size = 20, shoot_type type = CLASSIC);
            ~EnemyBulletComponent() = default;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packets, ECS::Entity &entity, float deltaTime) override;

            void setTarget(std::vector<int> target) { _target = std::move(target); };

        protected:
            void move_velocitically(const std::shared_ptr<PositionComponent>& positionComponent, float deltaTime, const std::shared_ptr<VelocityComponent>& velocityComponent) ;
            void move_to_target(const std::shared_ptr<PositionComponent>& positionComponent, float deltaTime, const std::shared_ptr<VelocityComponent>& velocityComponent);

        private:
            int damage = 1;
            int _x_bullet_size{};
            int _y_bullet_size{};
            std::vector<int> _target;
            shoot_type _type = CLASSIC;
    };
}
