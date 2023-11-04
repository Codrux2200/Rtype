/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ScoreBoardComponent
*/

#include "ScoreBoardComponent.hpp"

namespace ECS{

    ScoreBoardComponent::ScoreBoardComponent()
    {
    }

    std::shared_ptr<IComponent> ScoreBoardComponent::clone() const {
        return std::make_shared<ScoreBoardComponent>();
    }
}