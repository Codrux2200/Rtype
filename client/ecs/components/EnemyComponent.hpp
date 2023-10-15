/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** enemyComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_

#include <string>
#include <memory>
#include "EventComponent.hpp"

namespace ECS {
    /**
     * @brief Enemy component
     *
     */
    class EnemyComponent : public ECS::EventComponent {
        public:
            /**
             * @brief Construct a new enemy Component object
             *
             * @param uid
             */
            EnemyComponent(eventCallback callback);
            /**
             * @brief Destroy the enemy Component object
             *
             */
            ~EnemyComponent() = default;
            /**
             * @brief clone the component
             *
             * @return std::shared_ptr<IComponent>
             */
            std::shared_ptr<IComponent> clone() const override;
            /**
             * @brief execute the component
             *
             * @param packetManager
             * @param packetsQueue
             * @param entity
             * @param dt
             */
            void execute(Network::PacketManager &packetManager, std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) final override;
        protected:
        private:
            int _speed = 100;
    };
}

#endif /* !ENEMYCOMPONENT_HPP_ */
