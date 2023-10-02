/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** hitboxComponent
*/

#ifndef HITBOXCOMPONENT_HPP_
#define HITBOXCOMPONENT_HPP_
#include "../AComponent.hpp"

namespace ECS {
    /**
     * @brief Hitbox component
     * 
     */
    class HitboxComponent : public ECS::AComponent {
        public:
            /**
             * @brief Construct a new hitbox Component object
             * 
             * @param x 
             * @param y
             * @param weight
             * @param height
             * @param uid
             */
            HitboxComponent(int x, int y, int weight, int height, int uid);
            /**
             * @brief Destroy the hitbox Component object
             * 
             */
            ~HitboxComponent();
            /**
             * @brief Get the X and Y hitbox object
             * 
             * @return std::vector<int>
             */
            std::vector<int> getValue() const final;
            /**
             * @brief Set the X and Y hitbox object
             * 
             * @param x
             * @param y
             */
            void setValue(int x, int y) final;
            
        protected:
        private:
            /**
             * @brief define the x hitbox of the entity
             * 
             */
            int _x;

            /**
             * @brief define the y hitbox of the entity
             * 
             */
            int _y;
            /**
             * @brief define the weight hitbox of the entity
             * 
             */
            int _weight;
            /**
             * @brief define the height of the hitbox of the entity
             * 
             */
            int _height;
    };
}

#endif /* !HITBOXCOMPONENT_HPP_ */
