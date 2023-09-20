/*
** EPITECH PROJECT, 2023
** Rtype
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
            virtual int getUid() override;
            /**
             * @brief Construct a new AComponent object
             * 
             * @param uid 
             */
            virtual void setUid(int uid) override;
        protected:
        private:
            /**
             * @brief UID of the component
             *  
             */
            int _uid;
    };
}

#endif /* !AComponent_HPP_ */
