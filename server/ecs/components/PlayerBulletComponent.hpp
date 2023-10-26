/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** PlayerBulletComponent
*/

#pragma once

#include "AComponent.hpp"

namespace ECS {
    class PlayerBulletComponent : public AComponent {
        public:
            PlayerBulletComponent() = default;
            ~PlayerBulletComponent() = default;

            [[nodiscard]] std::shared_ptr<IComponent> clone() const override;



            int speed = 400;
            int damage = 1;
    };
}
