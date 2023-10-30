/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Component
*/

#pragma once

#include "AComponent.hpp"

namespace ECS {
    class Component : public AComponent {
        public:
            /**
             * @brief Constructor for the Component class.
             * @param type The type of the component to be initialized.
             */
            Component(ComponentType type);

            /** @brief Destructor for the Component class. */
            ~Component();


        protected:
        private:
    };
}
