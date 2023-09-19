/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** Acomponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include <string>

namespace ECS {
    class Acomponent : public IComponent {
        public:
            Acomponent();
            ~Acomponent();
            /**
             * @brief unique component UID
             * 
             */
            int UID;

        protected:
        private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
