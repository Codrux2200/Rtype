/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** AComponent
*/

#ifndef AComponent_HPP_
#define AComponent_HPP_
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
            int getUid();
            /**
             * @brief Construct a new AComponent object
             * 
             * @param uid 
             */
            void setUid(int uid);
        protected:
        private:
    };
}

#endif /* !AComponent_HPP_ */
