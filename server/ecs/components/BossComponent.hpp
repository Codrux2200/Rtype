/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#pragma once

#include <functional>
#include "AGameComponent.hpp"
#include "BossStateData.hpp"
#include "HitboxComponent.hpp"

namespace ECS {
    using bossShootFunction = std::function<void()>;
    class BossComponent : public ECS::AGameComponent {
        public:
            explicit BossComponent(bossShootFunction shootFunction);

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

        private:
            void _comingUpdate(ECS::Entity &entity, float dt);
            void _idleUpdate();
            void _dashUpdate(ECS::Entity &entity, float dt);
            void _moveUpdate(ECS::Entity &entity, float dt);
            void _attackUpUpdate(ECS::Entity &entity);
            void _attackDownUpdate(ECS::Entity &entity);
            void _shootUpdate();

            [[nodiscard]] static std::shared_ptr<HitboxComponent> _getHitboxStartingAt(ECS::Entity &entity, int x, int y) ;

            Network::data::BossState _state = Network::data::BossState::COMING;
            float _timer = 0;
            float _speed = 100;
            int _step = 0;
            float _isUp = 1;
            bossShootFunction _shootFunction;
    };
} // namespace ECS
