/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserMouthComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {
    /**
     * @brief Boss Laser Mouth Component
    */
    class BossLaserMouthComponent : public AGameComponent {
        public:
            /**
             * @brief Construct a new Boss Laser Mouth Component object
             * 
            */
            BossLaserMouthComponent() = default;
            /**
             * @brief Construct a new Boss Laser Mouth Component object
             * 
             * @param other the component to copy
            */
            BossLaserMouthComponent(const BossLaserMouthComponent& other);

            /**
             * @brief Clone the component
            */ 
            std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief update the boss laser mouth
             * 
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
            */
            void update(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

        private:
            /**
             * @brief the timer
            */
            float _timer = 0;
    };

} // namespace ECS

