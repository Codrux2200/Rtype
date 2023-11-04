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
    /**
     * @brief Boss Component
     */
    class BossComponent : public ECS::AGameComponent {
        public:
            /**
             * @brief Construct a new Boss Component object
             * 
             */
            explicit BossComponent(bossLaserGenerator laserGenerator);
            BossComponent(const BossComponent &other);
            ~BossComponent() = default;

            /**
             * @brief update the boss
             * 
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
            */
            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            /**
             * @brief clone the component
             * 
             * @return std::shared_ptr<IComponent> the cloned component
            */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief action to do when the boss is destroyed
             * 
             * @param entity the entity
             * @param texture the texture
             * @param dt the delta time
            */
            bool onDestroy(ECS::Entity &entity, Network::data::DeathReason reason, float dt) override;

            /**
             * @brief set the boss state
             * 
             * @param state the state
            */
            void setState(Network::data::BossState state, int isUp);

        private:
            /**
             * @brief the coming update of the boss state
             * 
             * @param entity the entity
             * @param dt the delta time
            */
            void _comingUpdate(ECS::Entity &entity, float dt);
            /**
             * @brief the dah update of the boss
             * 
             * @param entity the entity
             * @param dt the delta time
            */
            void _dashUpdate(ECS::Entity &entity, float dt);
            /**
             * @brief the move update of the boss
             * 
             * @param entity the entity
             * @param dt the delta time
            */
            void _moveUpdate(ECS::Entity &entity, float dt);
            /**
             * @brief the attack up update of the boss
             * 
             * @param entity the entity
            */
            void _attackUpUpdate(ECS::Entity &entity);
            /**
             * @brief the attack down update of the boss
             * 
             * @param entity the entity
            */
            void _attackDownUpdate(ECS::Entity &entity);
            /**
             * @brief the shoot update of the boss
             * 
             * @param entity the entity
            */
            void _shootUpdate();
            /**
             * @brief the idle update of the boss
             * 
             * @param entity the entity
            */
            void _idleUpdate(ECS::Entity &entity);

            /**
             * @brief set the idle texture
             * 
             * @param entity the entity
            */
            void _setIdleTexture(ECS::Entity &entity);
            /**
             * @brief set the dash texture
             * 
             * @param entity the entity
            */
            void _setAttackUpLoadingTexture(ECS::Entity &entity);
            /**
             * @brief set the dash texture
             * 
             * @param entity the entity
            */
            void _setAttackUpTexture(ECS::Entity &entity);
            /**
             * @brief set the dash texture
             * 
             * @param entity the entity
            */
            void _setAttackDownLoadingTexture(ECS::Entity &entity);
            /**
             * @brief set the dash texture
             * 
             * @param entity the entity
            */
            void _setAttackDownTexture(ECS::Entity &entity);

            bool _deathInitialized = false;
            Network::data::BossState _state = Network::data::COMING;
            /**
             * @brief the boss timer
             * 
            */
            float _timer = 0;
            /**
             * @brief the boss step
             * 
            */
            int _step = 0;
            /**
             * @brief the boss speed
             * 
            */
            float _speed = 300;
            /**
             * @brief the boss direction
             * 
            */
            float _isUp = 1;

            bossLaserGenerator _laserGenerator;

            /**
             * @brief the boss idle texture
             * 
            */ 
            std::shared_ptr<sf::Texture> _idleTexture;
            /**
             * @brief the boss attack up texture
             * 
            */
            std::shared_ptr<sf::Texture> _attackUpTexture;
            /**
             * @brief the boss attack down texture
             * 
            */
            std::shared_ptr<sf::Texture> _attackDownTexture;
            std::shared_ptr<sf::Texture> _deathTexture;
//            sf::Texture _dashTexture;
    };
}