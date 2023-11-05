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
            /**
             * @brief Construct a new Boss Component object
             *
             * @param shootFunction the shoot function
             */
            explicit BossComponent(bossShootFunction shootFunction);

            /**
             * @brief Clone a Boss Component
             *
            */ 
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief update the boss
             *
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
            */
            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            /**
             * @brief action to do when the boss is destroyed
             *
             * @param entity the entity
             * @param texture the texture
             * @param dt the delta time
            */
            bool onDestroy(Entity &entity, Network::data::DeathReason reason, float dt) override;

            /**
             * @brief get the scene change
            */
            SceneType getSceneChange() override;

        private:
            /**
             * @brief update the boss state
            */
            void _comingUpdate(ECS::Entity &entity, float dt);
            /**
             * @brief update the idle boss state
            */
            void _idleUpdate();
            /**
             * @brief update the dash boss state
            */
            void _dashUpdate(ECS::Entity &entity, float dt);
            /**
             * @brief update the move boss state
            */
            void _moveUpdate(ECS::Entity &entity, float dt);
            /**
             * @brief update the attack boss state
            */
            void _attackUpUpdate(ECS::Entity &entity);
            /**
             * @brief update the attack boss state
            */
            void _attackDownUpdate(ECS::Entity &entity);

            /**
             * @brief update the shoot
            */
            void _shootUpdate();

            /**
             * @brief get the hitbox starting at
             *
             * @param entity the entity
             * @param x the x
             * @param y the y
             * @return std::shared_ptr<HitboxComponent> the hitbox
            */
            [[nodiscard]] static std::shared_ptr<HitboxComponent> _getHitboxStartingAt(ECS::Entity &entity, int x, int y);

            /**
             * @brief the state
            */
            Network::data::BossState _state = Network::data::BossState::COMING;
            /**
             * @brief the timer
            */
            float _timer = 0;
            /**
             * @brief the speed
            */
            float _speed = 300;
            /**
             * @brief the step
            */
            int _step = 0;
            /**
             * @brief the is up
            */
            float _isUp = 1;
            /**
             * @brief the shoot function
            */
            bossShootFunction _shootFunction;
            /**
             * @brief the death initialized
            */
            bool _deathInitialized = false;
            /**
             * @brief the scene type
            */
            SceneType _sceneType = SceneType::GAME;
    };
} // namespace ECS
