/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    class BossComponent : public ECS::AGameComponent {
        public:
            BossComponent() = default;
            ~BossComponent() = default;

            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            bool onDestroy(ECS::Entity &entity, Network::data::DeathReason reason, float dt) override;

            void setState(Entity::BossState state);

        private:
            void _comingUpdate(ECS::Entity &entity, float dt);
            void _dashUpdate(ECS::Entity &entity, float dt);
            void _moveUpdate(ECS::Entity &entity, float dt);
            void _attackUpUpdate(ECS::Entity &entity);
            void _attackDownUpdate(ECS::Entity &entity);
            void _shootUpdate();

            bool _soundPlayed = false;
            Entity::BossState _state = Entity::COMING;
            float _timer = 0;
            int _step = 0;
            float _speed = 100;
            float _isUp = 1;

    };
}