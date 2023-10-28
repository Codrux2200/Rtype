/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** scene
*/

#pragma once

#include "AComponent.hpp"

class EnemyComponent : public ECS::AComponent {
    public:
        EnemyComponent();
        ~EnemyComponent() = default;

        [[nodiscard]] std::shared_ptr<ECS::IComponent> clone() const override;

};
