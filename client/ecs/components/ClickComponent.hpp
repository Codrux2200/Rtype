/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ClickComponent
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "AComponent.hpp"
#include "AEventComponent.hpp"
#include "Connection.hpp"
#include "PacketManager.hpp"

namespace ECS {
    using eventCallback = std::function<void(std::vector<Network::Packet> &, ECS::Entity &)>;
    class ClickComponent : public AEventComponent {
        public:
            ClickComponent(sf::Rect<int> rect, eventCallback callback, sf::RenderWindow &window);

            [[nodiscard]] std::vector<int> getValue() const final;
            void setValue(std::vector<int> values) final;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;

            void execute(std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt) final ;

        private:
            sf::Rect<int> _rect;
            sf::RenderWindow &_window;
            eventCallback _callback;
    };
}
