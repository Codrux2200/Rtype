/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** healthComponent
*/

#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_
#include "Acomponent.hpp"

namespace ECS {
    class HealthComponent : public ECS::Acomponent {
        public:
            /**
             * @brief Construct a new health Component object
             * 
             * @param uid 
             */
            HealthComponent(int uid);
            /**
             * @brief Destroy the health Component object
             * 
             */
            ~HealthComponent();
            /**
             * @brief Set the health of the entity
             * 
             * @param health
             */
            void setHealth(int health);
            /**
             * @brief Get the health of the entity
             * 
             * @return int
             */
            int getHealth() const;
        protected:
        private:
            int health;
    };
}
#endif /* !HEALTHCOMPONENT_HPP_ */
