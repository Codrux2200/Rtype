/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <vector>
#include <memory>

namespace ECS {
    /**
     * @brief ComponentType
     *
     */
    enum ComponentType
    {
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

    class IComponent {
        public:
            /**
             * @brief Get the Value object
             *
             * @return the value asked
             */
            virtual std::vector<int> getValue() const = 0;
            /**
             * @brief Set the Value object
             *
             * @param valueA
             *
             * @param valueB
             */
            virtual void setValue(std::vector<int> values) = 0;

            // Clone
            virtual std::shared_ptr<IComponent> clone() const = 0;

            virtual void setEnabled(bool enabled) = 0;

            virtual bool isEnabled() const = 0;

            virtual ComponentType getType() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
