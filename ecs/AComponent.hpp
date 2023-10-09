/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include <vector>

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
            int _uid;
            /**
             * @brief Get the Value object
             * 
             * @return the value asked
             */
            virtual std::vector<int> getValue() const;
            /**
             * @brief Set the Value object
             * 
             * @param valueA
             * 
             * @param valueB
             */
            virtual void setValue(int valueA, int valueB);
        protected:
        private:
            
    };
}

#endif /* !AComponent_HPP_ */
