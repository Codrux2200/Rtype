/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** shootComponent
*/

#pragma once
#include "AComponent.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include "AEventComponent.hpp"
#include "EntityFactory.hpp"
#include "PositionComponent.hpp"
#include "SFML/Graphics.hpp"
#include "SpriteComponent.hpp"

namespace ECS {
    /**
     * @brief Shoot component
     *
     */
    class ShootComponent : public ECS::AEventComponent {
        public:
            ShootComponent() = default;
            ~ShootComponent() = default;

            /**
             * @brief Execute the event
             * 
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
            */
            bool execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) override;

            /**
             * @brief Clone the component
            */
            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;
    };
}
