/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <vector>

namespace ECS {
    /**
     * @brief ComponentType
     * 
     */
    enum ComponentType
    {
        /**
         * @brief Sprite component
         * 
        */
        SPRITE = 0,
        /**
         * @brief Hitbox component
         * 
        */
        HITBOX = 1,
        /**
         * @brief Sound component
         * 
        */
        SOUND = 2,
    };

    class IComponent {
        public:
            /**
             * @brief Get the Value object
             * 
             * @return the value asked
             */
            virtual std::vector<int> getValue() const = 0;
            /**
             * @brief Set the Value object
             * 
             * @param valueA
             * 
             * @param valueB
             */
            virtual void setValue(int valueA, int valueB) = 0;
        protected:
        private:
    };
}

#endif /* !ICOMPONENT_HPP_ */
