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
    /**
     * @brief ScoreBoard Component
     */
    class ScoreBoardComponent : public AComponent{
        public:
            /**
             * @brief Construct a new ScoreBoard Component object
             *
             */ 
            ScoreBoardComponent();
            ~ScoreBoardComponent() = default;
            
            /**
             * @brief Clone the component
             *
             */ 
            std::shared_ptr<IComponent> clone() const override;
        protected:
        private:
    };
}

#endif /* !SCOREBOARDCOMPONENT_HPP_ */
