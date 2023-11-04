/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ControlComponent
*/

#pragma once

#include <memory>
#include <string>
#include "AEventComponent.hpp"

namespace ECS {
    /**
     * @brief Control Component
     */
    class ControlComponent : public AEventComponent {
        public:
            /**
             * @brief Construct a new Control Component object
             * 
             */
            ControlComponent();

            /**
             * @brief Get the Value object
             * 
             * @return std::vector<int> the value
             */
            [[nodiscard]] std::vector<int> getValue() const final;

            /**
             * @brief Set the Value object
             * 
             * @param values the value
             */
            void setValue(std::vector<int> values) final;

            /**
             * @brief clone the component
             * 
             * @return std::shared_ptr<IComponent> the cloned component
             */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            /**
             * @brief execute the event
             * 
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
             */
            void execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) final;

    };
}
