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
    /**
     * @brief Click Component
     */
    using eventCallback = std::function<void(std::vector<Network::Packet> &, ECS::Entity &)>;
    class ClickComponent : public AEventComponent {
        public:
            /**
             * @brief Construct a new Click Component object
             * 
             * @param rect the rect
             * @param callback the callback
             * @param window the window
             */
            ClickComponent(sf::Rect<int> rect, eventCallback callback, sf::RenderWindow &window);

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
            void execute(std::vector<Network::Packet> &packetsQueue, Entity &entity, float dt) final ;

        private:
            /**
             * @brief the rect
             */
            sf::Rect<int> _rect;
            /**
             * @brief the window
             */
            sf::RenderWindow &_window;
            /**
             * @brief the callback
            */
            eventCallback _callback;
    };
}
