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
    class AEventComponent : public AComponent {
        public:
            virtual bool execute(std::vector<Network::Packet> &packetsQueue, ECS::Entity &entity, float dt) = 0;
    };
}
