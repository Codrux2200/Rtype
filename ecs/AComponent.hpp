/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include <string>

namespace ECS {
    /**
     * @brief AComponent class
     * 
     */
    class AComponent : public IComponent {
        public:
            /**
             * @brief Construct a new AComponent object
             * 
             * @return the uid of the component
             */
            int getUid() override;
            /**
             * @brief Construct a new AComponent object
             * 
             * @param uid 
             */
            void setUid(int uid) override;
        protected:
        private:
    };
}

#endif /* !AComponent_HPP_ */
