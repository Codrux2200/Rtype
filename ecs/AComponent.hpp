/*
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
             * @brief UID of the component
             *
             */
            /**
             * @brief Get the Value object
             *
             * @return the value asked
             */
            virtual std::vector<int> getValue() const override;
            /**
             * @brief Set the Value object
             *
             * @param valueA
             *
             * @param valueB
             */
            virtual void setValue(int valueA, int valueB) override;

            void setEnabled(bool enabled) override;

            bool isEnabled() const override;

            ComponentType getType() const override;

        protected:
            bool _isEnabled = true;
            ComponentType _type;

    };
}

#endif /* !AComponent_HPP_ */
