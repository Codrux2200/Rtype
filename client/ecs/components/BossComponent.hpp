/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossComponent
*/

#pragma once

#include "AGameComponent.hpp"
#include "SFML/Graphics/Texture.hpp"

using bossLaserGenerator = std::function<void(const std::string &, float, float)>;

namespace ECS {
    class BossComponent : public ECS::AGameComponent {
        public:
            explicit BossComponent(bossLaserGenerator laserGenerator);
            BossComponent(const BossComponent &other);
            ~BossComponent() = default;

            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            bool onDestroy(ECS::Entity &entity, Network::data::DeathReason reason, float dt) override;

            void setState(Network::data::BossState state, int isUp);

        private:
            void _comingUpdate(ECS::Entity &entity, float dt);
            void _dashUpdate(ECS::Entity &entity, float dt);
            void _moveUpdate(ECS::Entity &entity, float dt);
            void _attackUpUpdate(ECS::Entity &entity);
            void _attackDownUpdate(ECS::Entity &entity);
            void _shootUpdate();
            void _idleUpdate(ECS::Entity &entity);

            void _setIdleTexture(ECS::Entity &entity);
            void _setAttackUpLoadingTexture(ECS::Entity &entity);
            void _setAttackUpTexture(ECS::Entity &entity);
            void _setAttackDownLoadingTexture(ECS::Entity &entity);
            void _setAttackDownTexture(ECS::Entity &entity);

            bool _deathInitialized = false;
            Network::data::BossState _state = Network::data::COMING;
            float _timer = 0;
            int _step = 0;
            float _speed = 300;
            float _isUp = 1;

            bossLaserGenerator _laserGenerator;

            std::shared_ptr<sf::Texture> _idleTexture;
            std::shared_ptr<sf::Texture> _attackUpTexture;
            std::shared_ptr<sf::Texture> _attackDownTexture;
            std::shared_ptr<sf::Texture> _deathTexture;
//            sf::Texture _dashTexture;
    };
}