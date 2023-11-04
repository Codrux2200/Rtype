/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ScoreBoardComponent
*/

#ifndef SCOREBOARDCOMPONENT_HPP_
#define SCOREBOARDCOMPONENT_HPP_
#include <iostream>
#include <memory>
#include "AComponent.hpp"

namespace ECS{
    class ScoreBoardComponent : public AComponent{
        public:
            ScoreBoardComponent();
            ~ScoreBoardComponent();
            std::shared_ptr<IComponent> clone() const override;
        protected:
        private:
    };
}

#endif /* !SCOREBOARDCOMPONENT_HPP_ */
