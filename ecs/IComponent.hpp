/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <memory>
#include <vector>
#include "DeadData.hpp"

namespace ECS {
    /**
     * @brief ComponentType
     *
     */
    enum ComponentType
    {
        NOTHING = -1,
        /**
         * @brief Sprite component
         *
        */
        DRAWABLE = 0,
        /**
         * @brief Hitbox component
         *
        */
        EVENT = 1,
        /**
         * @brief Sound component
         *
        */
        AUDIBLE = 2,


    };

    class Entity;

    class IComponent {
        public:
            /**
             * @brief Get the Value object
             *
             * @return the value asked
             */
            [[nodiscard]] virtual std::vector<int> getValue() const = 0;
            /**
             * @brief Set the Value object
             *
             * @param valueA
             *
             * @param valueB
             */
            virtual void setValue(std::vector<int> values) = 0;

            // Clone
            [[nodiscard]] virtual std::shared_ptr<IComponent> clone() const = 0;

            [[nodiscard]] virtual ComponentType getType() const = 0;

            virtual bool onDestroy(Entity &entity, Network::data::DeathReason reason) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
