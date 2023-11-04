/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AEventComponent
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include "Connection.hpp"
#include "AComponent.hpp"
#include "Entity.hpp"

namespace ECS {
    /**
     * @brief AEventComponent
     */
    class AEventComponent : public AComponent {
        public:
            /**
             * @brief execute the event
             * 
             * @param packetsQueue the packets queue
             * @param entity the entity
             * @param dt the delta time
             */
            virtual void execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) = 0;
    };
}
