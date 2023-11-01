/**
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include <vector>
#include "IComponent.hpp"

namespace ECS {
    /**
     * @brief AComponent class
     *
     */
    class AComponent : public IComponent {
        public:
            /**
             * @brief Get the Value object
             *
             * @return the value asked
             */
            [[nodiscard]] std::vector<int> getValue() const override;
            /**
             * @brief Set the Value object
             *
             * @param valueA
             *
             * @param valueB
             */
            void setValue(std::vector<int> values) override;

            [[nodiscard]] ComponentType getType() const override;

            bool onDestroy(Entity &entity, Network::data::DeathReason reason, float dt) override;

            bool isEnabled = true;
        protected:
            ComponentType _type = ComponentType::NOTHING;
    };
}

#endif /* !AComponent_HPP_ */
