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
            Component(ComponentType type);

            ~Component();


        protected:
        private:
    };
}
