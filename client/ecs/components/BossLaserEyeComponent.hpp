/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** BossLaserEyeComponent
*/

#pragma once

#include "AGameComponent.hpp"

namespace ECS {

class BossLaserEyeComponent : public AGameComponent {
    /**
     * @brief Boss Laser Eye Component
    */
    public:
        /**
         * @brief Construct a new Boss Laser Eye Component object
         * 
        */
        BossLaserEyeComponent() = default;
        /**
         * @brief Construct a new Boss Laser Eye Component object
         * 
         * @param other the component to copy
        */
        BossLaserEyeComponent(const BossLaserEyeComponent &other);

        /**
         * @brief Clone the component
         * 
        */ 
        [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

        /**
         * @brief update the boss laser eye
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
